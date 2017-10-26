#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QList>
#include <QTreeView>
#include <QTreeWidgetItem>

#include "note.h"

class Note;

class Notebook : public QTreeWidgetItem {

private:

    QString name; // The notebook name
    QList<Note*> notes; // The notes in this notebook
    Note *currentNote; // The note user is working on
    QTreeWidgetItem *p;

    static bool comparator(Note* a, Note* b);

public:

    explicit Notebook(QString name, QTreeWidgetItem *emptyParent);

    ~Notebook();

    QString& getName();

    QString text(int column) const;

    QIcon icon(int column) const;

    QString statusTip(int column) const;

    QString toolTip(int column) const;

    QTreeWidgetItem* parent() const;

    QTreeWidgetItem* child(int index) const;

    int childCount() const;

    int columnCount() const;

    int indexOfChildNote(Note *child) const;

    Qt::ItemFlags flags() const;

    void addChildNote(Note* nt);

    void addChild(QTreeWidgetItem *child);

    QVariant data(int column, int role) const;

    void setData(int column, int role, const QVariant &value);

    bool operator<(const QTreeWidgetItem &other) const;
};

#endif // NOTEBOOK_H
