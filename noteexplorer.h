#ifndef NOTEEXPLORER_H
#define NOTEEXPLORER_H

#include <QTreeWidget>

#include "notebook.h"
#include "treemodel.h"

class NoteExplorer : public QTreeWidget
{
    Q_OBJECT

private:
    QList<NoteBook*> notebooks; // All the open notebooks
    NoteBook* currentNotebook; // The notebook user is working on

public:
    explicit NoteExplorer(TreeModel *treeModel);
    ~NoteExplorer();

    bool insertNotebook(int position, NoteBook* nb);
    void addNotebok(NoteBook* nb);
};

#endif // NOTEEXPLORER_H
