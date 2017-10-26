#include "noteexplorer.h"

NoteExplorer::NoteExplorer(TreeModel *qaiModel){
//    setModel(qaiModel);
}

NoteExplorer::~NoteExplorer(){
    qDeleteAll(notebooks);
    delete currentNotebook;
}

bool NoteExplorer::insertNotebook(int position, Notebook *nb){
    if (position < 0 || position > notebooks.size())
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

void NoteExplorer::addNotebok(Notebook *nb){
    QModelIndex index = selectionModel()->currentIndex();
    QAbstractItemModel *m = model();

    int position = notebooks.size() - 1; // at the end

    if (m->columnCount(index) == 0) {
        if (!m->insertColumn(0, index))
            return;
    }

    if (!m->insertRow(0, index))
        return;

    QModelIndex child = m->index(position, 0, index);
    m->setData(child, QVariant(nb->getName()), Qt::EditRole);

    selectionModel()->setCurrentIndex(child, QItemSelectionModel::ClearAndSelect);

    notebooks.append(nb);
}
