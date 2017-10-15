#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsView>
#include <QScrollArea>

class Note : public QGraphicsView, QScrollArea
{
    Q_OBJECT

public:
    explicit Note();
    ~Note();
};

#endif // NOTE_H
