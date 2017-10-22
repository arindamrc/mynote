#ifndef EMPTYTREEITEM_H
#define EMPTYTREEITEM_H

#include "treeitem.h"
#include "notebook.h"

class Notebook;

class EmptyTreeItem : public TreeItem {

public:
    explicit EmptyTreeItem() : TreeItem(0){
    }

    ~EmptyTreeItem();

    TreeItem *child(int number);
    int childCount() const;
    QVariant data() const;
    bool insertChildren(int position, int rows);
    TreeItem *parent();
    bool removeChildren(int position, int count);
    int childNumber() const;
    bool setData(const QVariant &value);
    int childIndex(const TreeItem* child);

private:
    QList<Notebook*> childNotebooks;

};

#endif // EMPTYTREEITEM_H
