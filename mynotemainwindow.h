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
    explicit MyNoteMainWindow(QWidget *parent_widget = 0);
    ~MyNoteMainWindow();

private:
    Ui::MyNoteMainWindow *ui;

    // The working directory
    QDir *workingDir;

    // All open notes
    NoteExplorer *explorer;

    // The note in focus
    Note *currentNote;

    // The app status bar
    QStatusBar *noteStatus;

    //Toolbars
    QToolBar *fileToolBar;
    QToolBar *formatToolBar;
    QToolBar *insertToolbar;
    QToolBar *drawToolBar;

    //setup
    void createAppDirectory();
    void createConnections();
    void createContextMenu();
    void createLayout();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    void loadNotebooks();

    //helpers and utilities
    void closeEvent();


private slots:

    // File Menu
    void file_newNotebook();
    void file_newNote();
    void file_saveNote();
    void file_openNotebook();
    void file_closeNotebook();
    void file_saveNotebookAs();
    void file_printNote();
    void file_quit();

    // Edit Menu
    void edit_undo();
    void edit_redo();
    void edit_cut();
    void edit_copy();
    void edit_paste();
    void edit_find();
    void edit_selectAll();

    // Insert Menu
    void insert_image();
    void insert_table();
    void insert_symbol();
    void insert_link();
    void insert_line();

    // Draw Menu
    void draw_pen();
    void draw_brush();
    void draw_eraser();
    void draw_highlighter();

    // Format Menu
    void format_paragraph();
    void format_bullet();
    void format_font();
    void format_underline();
    void format_highlight();
    void format_italics();
    void format_group();
    void format_ungroup();

    // Help Menu
    void help_aboutMyNote();
    void help_usage();
    void help_license();


};

#endif // MYNOTEMAINWINDOW_H
