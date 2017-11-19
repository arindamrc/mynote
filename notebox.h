#ifndef NOTEBOX_H
#define NOTEBOX_H

#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QTextEdit>

#include "note.h"
#include "globals.h"

class Note;

QT_BEGIN_NAMESPACE
class QFocusEvent;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneHoverEvent;
QT_END_NAMESPACE

class NoteBox : public QGraphicsTextItem
{
    Q_OBJECT

private:
    static unsigned int globalId; // an ID counter

    int id; // The unique identifier of this notebox
    QPointF pos; // The location of the notebox
    double theta; // The rotation of the notebox

    Note *parentNote; // The note this box belongs to

    void setUp();

//protected:
//    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
//    void focusOutEvent(QFocusEvent *event) override;
//    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
//    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
//    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

public:
    explicit NoteBox(Note* parent, QPointF pos, double rot = globals::boxOrientation);

    ~NoteBox();
};
#endif // NOTEBOX_H
