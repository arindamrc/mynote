#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QList>

#include "note.h"
#include "treeitem.h"

class Note;
class EmptyTreeItem;

class Notebook : public TreeItem {

private:

    QString name; // The notebook name
    QList<Note*> notes; // The notes in this notebook
    Note *currentNote; // The note user is working on

public:

    explicit Notebook(QString name, EmptyTreeItem* parent) : TreeItem((TreeItem*)parent) {
        this->name = name;
    }

    explicit Notebook(EmptyTreeItem *parent) : TreeItem((TreeItem*) parent){
    }

    ~Notebook();

    // TreeItem methods
    TreeItem *child(int number);
    int childCount() const;
    QVariant data() const;
    bool insertChildren(int position, int rows);
    TreeItem *parent();
    bool removeChildren(int position, int count);
    int childNumber() const;
    bool setData(const QVariant &value);
    int childIndex(const TreeItem* child);

    QString& getName(){
        return name;
    }

    bool insertNote(int position, Note* nt);
    void addNote(Note* nt);
};

#endif // NOTEBOOK_H
