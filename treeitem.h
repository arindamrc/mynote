#ifndef TREEITEM_H
#define TREEITEM_H

#include <QVector>
#include <QVariant>

class TreeItem {

public:
    explicit TreeItem(TreeItem *parent = 0){
        parentItem = parent;
    }

    virtual ~TreeItem();

    virtual TreeItem *child(int number) = 0;
    virtual int childCount() const  = 0;
    virtual QVariant data() const = 0;
    virtual bool insertChildren(int position, int rows) = 0;
    virtual TreeItem *parent() = 0;
    virtual bool removeChildren(int position, int count) = 0;
    virtual int childNumber() const = 0;
    virtual bool setData(const QVariant &value) = 0;
    virtual int childIndex(const TreeItem* child) = 0;

protected:
    TreeItem *parentItem;
};

#endif // TREEITEM_H
