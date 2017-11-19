#include "notebook.h"

#include <QStringList>
#include <QDebug>

NoteBook::NoteBook(QString name, QTreeWidgetItem *emptyParent) : QTreeWidgetItem(emptyParent) {
    this->name = name;
    this->p = emptyParent;
}

NoteBook::~NoteBook(){
    delete p;
    qDeleteAll(notes);
}

bool NoteBook::comparator(Note *a, Note *b){
    if (a->getName() < b->getName()){
        return true;
    }
    else {
        return false;
    }
}

QString& NoteBook::getName(){
    return name;
}

QString NoteBook::text(int column) const{
    return this->name;
}

QIcon NoteBook::icon(int column) const{
    return QIcon(":/resources/notebook.png");
}

QString NoteBook::statusTip(int column) const{
    return this->name;
}

QString NoteBook::toolTip(int column) const {
    return this->name;
}

QTreeWidgetItem* NoteBook::parent() const{
    return QTreeWidgetItem::parent();
}

void NoteBook::addChild(QTreeWidgetItem *child){
    QTreeWidgetItem::addChild(child);
    notes.append((Note*)child);
    QTreeWidgetItem::sortChildren(0, Qt::AscendingOrder);
    std::sort(notes.begin(), notes.end(), NoteBook::comparator);
}

QTreeWidgetItem* NoteBook::child(int index) const{
    return (QTreeWidgetItem*)notes.at(index);
}

int NoteBook::childCount() const {
    return notes.size();
}

int NoteBook::columnCount() const {
    return 1;
}

int NoteBook::indexOfChildNote(Note *child) const{
    return notes.indexOf(child);
}

Qt::ItemFlags NoteBook::flags() const{
    return (Qt::ItemIsEditable | Qt::ItemNeverHasChildren);
}

void NoteBook::addChildNote(Note *nt){
    QTreeWidgetItem::addChild((QTreeWidgetItem*)nt);
    notes.append(nt);
    QTreeWidgetItem::sortChildren(0, Qt::AscendingOrder);
    std::sort(notes.begin(), notes.end(), NoteBook::comparator);
}

QVariant NoteBook::data(int column, int role) const{
    switch (role) {
    case Qt::DisplayRole:
        return text(column);
        break;
    case Qt::DecorationRole:
        return icon(column);
        break;
    case Qt::StatusTipRole:
        return statusTip(column);
        break;
    case Qt::ToolTipRole:
        return toolTip(column);
        break;
    default:
        return QTreeWidgetItem::data(column, role);
    }
}

void NoteBook::setData(int column, int role, const QVariant &value){
    QTreeWidgetItem::setData(column, role, value);
    this->name = value.toString();
}

bool NoteBook::operator <(const QTreeWidgetItem &other) const{
    NoteBook& o = (NoteBook&) other;
    if(this->name < o.getName()){
        return true;
    } else {
        return false;
    }
}
