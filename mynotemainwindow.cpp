#include "mynotemainwindow.h"
#include "ui_mynotemainwindow.h"

MyNoteMainWindow::MyNoteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNoteMainWindow)
{
    ui->setupUi(this);
}

MyNoteMainWindow::~MyNoteMainWindow()
{
    delete ui;
}
