#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScrollArea>
#include <QTextEdit>

#include "notebox.h"
#include "notebook.h"
#include "globals.h"

class NoteBook;
class NoteBox;
class QGraphicsSceneMouseEvent;

class Note : public QGraphicsScene, public QTreeWidgetItem
{
    Q_OBJECT

private:
    QString name; // The note name
    QList<NoteBox*> noteBoxes; // The noteboxes in this note
    NoteBox *boxInFocus; // The box currently in focus. A box is created wherever the user clicks on the note.
    NoteBook* p;
    bool opened = false;
    QGraphicsView* noteView;

    // Set up the note with the graphics scene
    void setUp();

    // make a NoteBox at the given location and orientation
    NoteBox* makeNoteBox(QPointF pos, double rot = globals::boxOrientation, double height = globals::boxHeight, double width = globals::boxWidth);

protected:
    // Override to capture mouse press
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

public:
    Note(QString name, NoteBook* p);

    Note() {} // default constructor

    ~Note();

    QString& getName();

    // QTreeWidgetItem's overridden methods
    QString text(int column) const;
    QIcon icon(int column) const;
    QString statusTip(int column) const;
    QString toolTip(int column) const;
    QTreeWidgetItem* parent() const;
    QTreeWidgetItem* child(int index) const;
    void addChild(QTreeWidgetItem *child);
    Qt::ItemFlags flags() const;
    int childCount() const;
    int columnCount() const;
    QVariant data(int column, int role) const;
    void setData(int column, int role, const QVariant &value);

    bool operator<(const QTreeWidgetItem &other) const;

    // Is the note open as a tab
    bool isOpen() const;

    // Open the note and add to the tabbed widget
    void openNote();

    // Close the note and remove from tabbed widget
    void closeNote();

    // Get the view associated with this scene
    QGraphicsView* getNoteView();
};

#endif // NOTE_H
