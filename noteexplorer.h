#ifndef NOTEEXPLORER_H
#define NOTEEXPLORER_H

#include <QTreeView>

class NoteExplorer : public QTreeView
{
    Q_OBJECT

public:
    explicit NoteExplorer();
    ~NoteExplorer();

};

#endif // NOTEEXPLORER_H
