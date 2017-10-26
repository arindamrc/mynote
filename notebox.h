#ifndef NOTEBOX_H
#define NOTEBOX_H

#include <QTextEdit>

#include "note.h"

class Note;

class Notebox : public QTextEdit
{
    Q_OBJECT

private:
    int id; // The unique identifier of this notebox
    int x, y; // The location of the notebox
    int theta; // The rotation of the notebox
    int h, w;  // The height and width of the box

    Note *p; // The note this box belongs to

public:
    explicit Notebox();
    ~Notebox();
};
#endif // NOTEBOX_H
