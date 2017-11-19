#include "note.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Note::Note(QString name, NoteBook *p) : QTreeWidgetItem((QTreeWidgetItem*)p) {
    qDebug() << "In note constructor...";
    this->name = name;
    this->p = p;
    this->p->addChild(this);
    this->noteView = new QGraphicsView();
    setUp();
}

Note::~Note(){
    qDeleteAll(noteBoxes);
    delete p;
    delete boxInFocus;
}

void Note::setUp(){
//    noteView->setRenderHints(noteView->renderHints() | QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
//    noteView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    noteView->setScene(this);
}

QString& Note::getName(){
    return this->name;
}

QString Note::text(int column) const{
    return this->name;
}

QIcon Note::icon(int column) const{
    return QIcon(":/resources/note.png");
}

QString Note::statusTip(int column) const{
    return this->name;
}

QString Note::toolTip(int column) const {
    return this->name;
}

void Note::addChild(QTreeWidgetItem *child){
    // do nothing
    return;
}

QTreeWidgetItem* Note::parent() const{
    return QTreeWidgetItem::parent();
}

QTreeWidgetItem* Note::child(int index) const{
    return 0; // no child
}

Qt::ItemFlags Note::flags() const{
    return (Qt::ItemIsEditable | Qt::ItemNeverHasChildren);
}

int Note::childCount() const {
    return 0;
}

int Note::columnCount() const {
    return 1;
}

QVariant Note::data(int column, int role) const{
    switch (role) {
    case Qt::DisplayRole:
        return text(column);
        break;
    case Qt::DecorationRole:
        return icon(column);
        break;
    case Qt::StatusTipRole:
        return statusTip(column);
        break;
    case Qt::ToolTipRole:
        return toolTip(column);
        break;
    default:
        return QTreeWidgetItem::data(column, role);
    }
}

void Note::setData(int column, int role, const QVariant &value){
    QTreeWidgetItem::setData(column, role, value);
    this->name = value.toString();
}

bool Note::operator <(const QTreeWidgetItem &other) const{
    Note& o = (Note&) other;
    if(this->name < o.getName()){
        return true;
    } else {
        return false;
    }
}

bool Note::isOpen() const{
    return opened;
}

void Note::openNote(){
    this->opened = true;
}

void Note::closeNote(){
    this->opened = false;
}

void Note::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    qDebug() << "Pressed mouse in note...";
    qDebug() << "pos:" << mouseEvent->scenePos().x() << "," << mouseEvent->scenePos().y();
    if(mouseEvent->button() == Qt::LeftButton){
        NoteBox* newNoteBox = makeNoteBox(mouseEvent->scenePos());
        qDebug() << "Made new notebox...";
        addItem(newNoteBox);
        noteBoxes.append(newNoteBox);
    }
}

NoteBox* Note::makeNoteBox(QPointF pos, double rot, double height, double width){
    NoteBox* box = new NoteBox(this, pos);
    return box;
}

QGraphicsView* Note::getNoteView(){
    return noteView;
}
