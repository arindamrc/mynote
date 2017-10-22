#ifndef NOTEEXPLORER_H
#define NOTEEXPLORER_H

#include <QTreeView>

#include "notebook.h"
#include "treemodel.h"

class NoteExplorer : public QTreeView
{
    Q_OBJECT

private:
    QList<Notebook*> notebooks; // All the open notebooks
    Notebook* currentNotebook; // The notebook user is working on

public:
    explicit NoteExplorer(TreeModel *treeModel);
    ~NoteExplorer();

    bool insertNotebook(int position, Notebook* nb);
    void addNotebok(Notebook* nb);
};

#endif // NOTEEXPLORER_H
