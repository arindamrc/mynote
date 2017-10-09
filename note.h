#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsView>

class Note : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Note();
    ~Note();
};

#endif // NOTE_H
