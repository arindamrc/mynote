#ifndef MYNOTEMAINWINDOW_H
#define MYNOTEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyNoteMainWindow;
}

class MyNoteMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyNoteMainWindow(QWidget *parent = 0);
    ~MyNoteMainWindow();

private:
    Ui::MyNoteMainWindow *ui;

    //Menus
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *insertMenu;
    QMenu *drawMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

    //Actions
};

#endif // MYNOTEMAINWINDOW_H
