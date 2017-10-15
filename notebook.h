#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QList>

#include <note.h>

class Notebook
{

private:
    QList<Note> notes;

public:
    Notebook() {}
};

#endif // NOTEBOOK_H
