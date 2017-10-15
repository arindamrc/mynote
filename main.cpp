#include <QApplication>

#include "mynotemainwindow.h"
#include "globals.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyNoteMainWindow w;
    w.show();

    a.setOrganizationName(globals::orgName);
    a.setApplicationName(globals::appName);
    a.setApplicationDisplayName(globals::appDisplayName);
    a.setApplicationVersion(globals::appVersion);
    a.setOrganizationDomain(globals::orgDomain);

    return a.exec();
}
