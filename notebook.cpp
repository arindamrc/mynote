#include "notebook.h"

#include <QStringList>
#include <QDebug>

Notebook::Notebook(QString name, QTreeWidgetItem *emptyParent) : QTreeWidgetItem(emptyParent) {
    this->name = name;
    this->p = emptyParent;
}

Notebook::~Notebook(){
    delete p;
    qDeleteAll(notes);
}

bool Notebook::comparator(Note *a, Note *b){
    if (a->getName() < b->getName()){
        return true;
    }
    else {
        return false;
    }
}

QString& Notebook::getName(){
    return name;
}

QString Notebook::text(int column) const{
    return this->name;
}

QIcon Notebook::icon(int column) const{
    return QIcon(":/resources/notebook.png");
}

QString Notebook::statusTip(int column) const{
    return this->name;
}

QString Notebook::toolTip(int column) const {
    return this->name;
}

QTreeWidgetItem* Notebook::parent() const{
    return QTreeWidgetItem::parent();
}

void Notebook::addChild(QTreeWidgetItem *child){
    QTreeWidgetItem::addChild(child);
    notes.append((Note*)child);
    QTreeWidgetItem::sortChildren(0, Qt::AscendingOrder);
    std::sort(notes.begin(), notes.end(), Notebook::comparator);
}

QTreeWidgetItem* Notebook::child(int index) const{
    return (QTreeWidgetItem*)notes.at(index);
}

int Notebook::childCount() const {
    return notes.size();
}

int Notebook::columnCount() const {
    return 1;
}

int Notebook::indexOfChildNote(Note *child) const{
    return notes.indexOf(child);
}

Qt::ItemFlags Notebook::flags() const{
    return (Qt::ItemIsEditable | Qt::ItemNeverHasChildren);
}

void Notebook::addChildNote(Note *nt){
    QTreeWidgetItem::addChild((QTreeWidgetItem*)nt);
    notes.append(nt);
    QTreeWidgetItem::sortChildren(0, Qt::AscendingOrder);
    std::sort(notes.begin(), notes.end(), Notebook::comparator);
}

QVariant Notebook::data(int column, int role) const{
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

void Notebook::setData(int column, int role, const QVariant &value){
    QTreeWidgetItem::setData(column, role, value);
    this->name = value.toString();
}

bool Notebook::operator <(const QTreeWidgetItem &other) const{
    Notebook& o = (Notebook&) other;
    if(this->name < o.getName()){
        return true;
    } else {
        return false;
    }
}
