#include "note.h"

Note::~Note(){
    delete parentItem;
}


TreeItem* Note::child(int number){
    return 0; //  A note doesn't have a child
}

int Note::childCount() const
{
    return 0; //  A note doesn't have a child
}

int Note::childNumber() const
{
    if (parentItem){
        Notebook* p = static_cast<Notebook*>(parentItem);
        return p->childIndex(this);
    }

    return 0;
}

QVariant Note::data() const
{
    return QVariant(this->name);
}

bool Note::insertChildren(int position, int rows)
{
    // Note has no children
    return false;
}

TreeItem *Note::parent()
{
    return parentItem;
}

bool Note::removeChildren(int position, int count)
{
    return false;
}

bool Note::setData(const QVariant &value)
{
    this->name = value.toString();
    return true;
}

int Note::childIndex(const TreeItem *child){
    return -1; // No children
}
