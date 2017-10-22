#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsView>
#include <QScrollArea>
#include <QTextEdit>

#include "notebox.h"
#include "treeitem.h"
#include "notebook.h"

class Notebook;
class Notebox;

class Note : public QGraphicsView, public TreeItem
{
    Q_OBJECT

private:
    QString name; // The note name
    QList<Notebox*> noteBoxes; // The noteboxes in this note
    Notebox *boxInFocus; // The box currently in focus. A box is created wherever the user clicks on the note.

public:
    explicit Note(QString name, Notebook *parent) : TreeItem((TreeItem*)parent){
        this->name = name;
    }

    explicit Note(Notebook *parent) : TreeItem((TreeItem*) parent) { }

    ~Note();

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
};

#endif // NOTE_H
