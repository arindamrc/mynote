#include <QDebug>

#include "notebox.h"


unsigned int NoteBox::globalId = 0; // an ID counter

NoteBox::NoteBox(Note* parent, QPointF pos, double rot) : QGraphicsTextItem(0) {
    qDebug() << "In NoteBox constructor...";
    this->id = NoteBox::globalId++;
    this->parentNote = parent;
    this->pos = pos;
    this->theta = rot;
    qDebug() << "NoteBox ID:" << this->id;
    setUp();
}

NoteBox::~NoteBox(){

}

void NoteBox::setUp(){
    qDebug() << "Setting up NoteBox: " << this->id;
    qDebug() << "pos:" << pos.x() << "," << pos.y();
    setPos(pos);
//    setRotation(theta);
//    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setDefaultTextColor(Qt::white);
    qDebug() << "Finished setting up NoteBox: " << this->id;
}

//QVariant NoteBox::itemChange(GraphicsItemChange change, const QVariant &value){
//    qDebug() << "Notebox changed";
//}

//void NoteBox::focusOutEvent(QFocusEvent *event){
//    qDebug() << "Notebox focus out";
//    setTextInteractionFlags(Qt::NoTextInteraction);
//    QGraphicsTextItem::focusOutEvent(event);
//}

//void NoteBox::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
//    if(textInteractionFlags() == Qt::NoTextInteraction){
//        setTextInteractionFlags(Qt::TextEditorInteraction);
//    }
//    QGraphicsItem::mouseDoubleClickEvent(event);
//}

//void NoteBox::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
//    qDebug() << "Inside note box";
//}

//void NoteBox::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
//    qDebug() << "leaving note box";
//}
