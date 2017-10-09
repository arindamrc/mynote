#ifndef MYNOTEMAINWINDOW_H
#define MYNOTEMAINWINDOW_H

#include <QMainWindow>
#include <QDir>

#include "note.h"
#include "noteexplorer.h"

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

    // The working directory
    QDir *workingDir;

    // The note in focus
    Note *currentNote;

    // All open notes
    NoteExplorer *explorer;

    // The app status bar
    QStatusBar noteStatus;

    //Menus
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *insertMenu;
    QMenu *drawMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;

    //Toolbars

    //Actions - FileMenu
    QAction *newNoteBook;
    QAction *newNote;
    QAction *saveNote;
    QAction *openNoteBook;
    QAction *closeNoteBook;
    QAction *saveAsNoteBook; //save as or export
    QAction *printNote;
    QAction *exit;

    //Actions - EditMenu
    QAction *undo;
    QAction *redo;
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *findAndReplace;
    QAction *selectAll;

    //Actions - InsertMenu
    QAction *imgInsert;
    QAction *tableInsert;
    QAction *symbolInsert;
    QAction *linkInsert;
    QAction *lineInsert;

    //Actions - DrawMenu
    QAction *pen;
    QAction *brush;
    QAction *eraser;
    QAction *thickness;
    QAction *highlighterPen; //free form

    //Actions - FormatMenu
    QAction *heading;
    QAction *subHeading;
    QAction *paragraph;
    QAction *bullets;
    QAction *fonts;
    QAction *underline;
    QAction *bold;
    QAction *highlight;
    QAction *italics;
    QAction *group;
    QAction *unGroup;

    //Actions - HelpMenu
    QAction *usage;
    QAction *licensing;
    QAction *about;

    //Toolbars
    QToolBar *fileToolBar;
    QToolBar *formatToolBar;
    QToolBar *insertToolbar;
    QToolBar *drawToolBar;

    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
};

#endif // MYNOTEMAINWINDOW_H
