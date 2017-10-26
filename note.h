#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsView>
#include <QScrollArea>
#include <QTextEdit>

#include "notebox.h"
#include "notebook.h"

class Notebook;
class Notebox;

class Note : public QGraphicsView, public QTreeWidgetItem
{
    Q_OBJECT

private:
    QString name; // The note name
    QList<Notebox*> noteBoxes; // The noteboxes in this note
    Notebox *boxInFocus; // The box currently in focus. A box is created wherever the user clicks on the note.
    Notebook* p;

public:
    Note(QString name, Notebook* p);

    ~Note();

    QString& getName();

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

};

#endif // NOTE_H
