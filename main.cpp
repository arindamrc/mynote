#include "mynotemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyNoteMainWindow w;
    w.show();

    return a.exec();
}
