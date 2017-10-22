#include "emptytreeitem.h"

#include <QStringList>

EmptyTreeItem::~EmptyTreeItem()
{
    delete parentItem;
    qDeleteAll(childNotebooks);
}

TreeItem *EmptyTreeItem::child(int number)
{
    return childNotebooks.value(number);
}

int EmptyTreeItem::childCount() const
{
    return childNotebooks.count();
}

int EmptyTreeItem::childNumber() const
{
    // This is the root
    return 0;
}


QVariant EmptyTreeItem::data() const
{
    return QVariant(); // empty tree node
}

bool EmptyTreeItem::insertChildren(int position, int rows)
{
    if (position < 0 || position > childNotebooks.size())
        return false;

    for(int i = 0; i < rows; i++){
        Notebook *item = new Notebook(this);
        childNotebooks.insert(position, item);
    }

    return true;
}

TreeItem *EmptyTreeItem::parent()
{
    return parentItem;
}

bool EmptyTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childNotebooks.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childNotebooks.takeAt(position);

    return true;
}

bool EmptyTreeItem::setData(const QVariant &value)
{
    return true; // no value at root
}

int EmptyTreeItem::childIndex(const TreeItem *child){
    Notebook* c = (Notebook*)child;
    return childNotebooks.indexOf(c);
}
