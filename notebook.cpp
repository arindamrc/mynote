#include "notebook.h"

#include <QStringList>

Notebook::~Notebook(){
    delete parentItem;
    qDeleteAll(notes);
}

TreeItem* Notebook::child(int number){
    return (TreeItem*) notes.value(number);
}

int Notebook::childCount() const
{
    return notes.count();
}

int Notebook::childNumber() const
{
    if (parentItem){
        return parentItem->childIndex((TreeItem*)this); // return the empty header data
    }

    return 0;
}

QVariant Notebook::data() const
{
    return QVariant(this->name);
}

bool Notebook::insertChildren(int position, int rows)
{
    if (position < 0 || position > notes.size())
        return false;

    for(int i = 0; i < rows; i++){
        Note *item = new Note(this);
        notes.insert(position, item);
    }

    return true;
}

TreeItem *Notebook::parent()
{
    return parentItem;
}

bool Notebook::removeChildren(int position, int count)
{
    if (position < 0 || position + count > notes.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete notes.takeAt(position);

    return true;
}

bool Notebook::setData(const QVariant &value)
{
    this->name = value.toString();
    return true;
}

int Notebook::childIndex(const TreeItem *child){
    Note* c = (Note*)child;
    return notes.indexOf(c);
}

bool Notebook::insertNote(int position, Note *nt){
    if (position < 0 || position > notes.size())
        return false;

    QModelIndex index = selectionModel()->currentIndex();
    QAbstractItemModel *m = model();

    if (m->columnCount(index) == 0) {
        if (!m->insertColumn(0, index))
            return false;
    }

    if (!m->insertRow(position, index))
        return false;

    QModelIndex child = m->index(position, 0, index);
    m->setData(child, QVariant(nb->getName()), Qt::EditRole);

    selectionModel()->setCurrentIndex(child, QItemSelectionModel::ClearAndSelect);

    notebooks.insert(position, nb);
    return true;
}

void Notebook::addNote(Note *nt){

}
