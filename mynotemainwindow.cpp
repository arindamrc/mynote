#include <QDebug>
#include <QSettings>
#include <QSplitter>
#include <QTextEdit>

#include "mynotemainwindow.h"
#include "ui_mynotemainwindow.h"
#include "globals.h"
#include "treemodel.h"

MyNoteMainWindow::MyNoteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNoteMainWindow)
{
    ui->setupUi(this);

    readSettings();
    createAppDirectory();
    createConnections();
    createLayout();
}

MyNoteMainWindow::~MyNoteMainWindow()
{
    delete ui;
}

void MyNoteMainWindow::readSettings(){
    QSettings settings;
}

void MyNoteMainWindow::writeSettings(){
    QSettings settings;
}

void MyNoteMainWindow::createAppDirectory(){
    workingDir = new QDir(globals::appHome);
    if(!workingDir->exists()){
        workingDir->mkpath(globals::appHome);
    }
}

void MyNoteMainWindow::createConnections(){
    connect(ui->actionNew_Note, SIGNAL(triggered(bool)), this, SLOT(file_newNote()));
    connect(ui->actionNew_Notebook, SIGNAL(triggered(bool)), this, SLOT(file_newNotebook()));
    connect(ui->actionAbout_MyNote, SIGNAL(triggered(bool)), this, SLOT(help_aboutMyNote()));
    connect(ui->actionBrush, SIGNAL(triggered(bool)), this, SLOT(draw_brush()));
    connect(ui->actionBullets, SIGNAL(triggered(bool)), this, SLOT(format_bullet()));
    connect(ui->actionClose_Notebook, SIGNAL(triggered(bool)), this, SLOT(file_closeNotebook()));
    connect(ui->actionCopy, SIGNAL(triggered(bool)), this, SLOT(edit_copy()));
    connect(ui->actionCut, SIGNAL(triggered(bool)), this, SLOT(edit_cut()));
    connect(ui->actionEraser, SIGNAL(triggered(bool)), this, SLOT(draw_eraser()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(file_quit()));
    connect(ui->actionFind_and_replace, SIGNAL(triggered(bool)), this, SLOT(edit_find()));
    connect(ui->actionFont, SIGNAL(triggered(bool)), this, SLOT(format_font()));
    connect(ui->actionGroup, SIGNAL(triggered(bool)), this, SLOT(format_group()));
    connect(ui->actionHighlight, SIGNAL(triggered(bool)), this, SLOT(format_highlight()));
    connect(ui->actionHighlighter, SIGNAL(triggered(bool)), this, SLOT(draw_highlighter()));
    connect(ui->actionImage, SIGNAL(triggered(bool)), this, SLOT(insert_image()));
    connect(ui->actionItalics, SIGNAL(triggered(bool)), this, SLOT(format_italics()));
    connect(ui->actionLicense, SIGNAL(triggered(bool)), this, SLOT(help_license()));
    connect(ui->actionLine, SIGNAL(triggered(bool)), this, SLOT(insert_line()));
    connect(ui->actionLink, SIGNAL(triggered(bool)), this, SLOT(insert_link()));
    connect(ui->actionOpen_Notebook, SIGNAL(triggered(bool)), this, SLOT(file_openNotebook()));
    connect(ui->actionParagraph, SIGNAL(triggered(bool)), this, SLOT(format_paragraph()));
    connect(ui->actionPaste, SIGNAL(triggered(bool)), this, SLOT(edit_paste()));
    connect(ui->actionPen, SIGNAL(triggered(bool)), this, SLOT(draw_pen()));
    connect(ui->actionPrint_Note, SIGNAL(triggered(bool)), this, SLOT(file_printNote()));
    connect(ui->actionRedo, SIGNAL(triggered(bool)), this, SLOT(edit_redo()));
    connect(ui->actionSave_Note, SIGNAL(triggered(bool)), this, SLOT(file_saveNote()));
    connect(ui->actionSave_Notebook_As, SIGNAL(triggered(bool)), this, SLOT(file_saveNotebookAs()));
    connect(ui->actionSelect_All, SIGNAL(triggered(bool)), this, SLOT(edit_selectAll()));
    connect(ui->actionSymbol, SIGNAL(triggered(bool)), this, SLOT(insert_symbol()));
    connect(ui->actionTable, SIGNAL(triggered(bool)), this, SLOT(insert_table()));
    connect(ui->actionUnderline, SIGNAL(triggered(bool)), this, SLOT(format_underline()));
    connect(ui->actionUndo, SIGNAL(triggered(bool)), this, SLOT(edit_undo()));
    connect(ui->actionUngroup, SIGNAL(triggered(bool)), this, SLOT(format_ungroup()));
    connect(ui->actionUsage, SIGNAL(triggered(bool)), this, SLOT(help_usage()));
}

void MyNoteMainWindow::createLayout(){
    TreeModel *treeModel = new TreeModel();
    explorer = new NoteExplorer(treeModel);
//    currentNote = new Note("dummy", new Notebook("dummy"));
    QSplitter *mainSplitter= new QSplitter();
    mainSplitter->addWidget(explorer);
    mainSplitter->addWidget(currentNote);
    mainSplitter->setStretchFactor(0,globals::defaultStretch_explorer);
    mainSplitter->setStretchFactor(1,globals::defaultStretch_note);
    setCentralWidget(mainSplitter);
    setWindowTitle(globals::appDisplayName);
}


// utilities

void MyNoteMainWindow::closeEvent(){
    writeSettings();
}

// Slots

void MyNoteMainWindow::file_newNotebook(){
    qDebug() << "New notebook";
}

void MyNoteMainWindow::file_newNote(){
    qDebug() << "New note";
}

void MyNoteMainWindow::file_saveNote(){
    qDebug() << "Save note";
}

void MyNoteMainWindow::file_openNotebook(){
    qDebug() << "Open notebook";
}

void MyNoteMainWindow::file_closeNotebook(){
    qDebug() << "Close notebook";
}

void MyNoteMainWindow::file_saveNotebookAs(){
    qDebug() << "Save notebook as";
}

void MyNoteMainWindow::file_printNote(){
    qDebug() << "Print note";
}

void MyNoteMainWindow::file_quit(){
    qDebug() << "Exit";
}

void MyNoteMainWindow::edit_undo(){

}

void MyNoteMainWindow::edit_redo(){

}

void MyNoteMainWindow::edit_cut(){

}

void MyNoteMainWindow::edit_copy(){

}

void MyNoteMainWindow::edit_paste(){

}

void MyNoteMainWindow::edit_find(){

}

void MyNoteMainWindow::edit_selectAll(){

}

void MyNoteMainWindow::insert_image(){

}

void MyNoteMainWindow::insert_line(){

}

void MyNoteMainWindow::insert_link(){

}

void MyNoteMainWindow::insert_symbol(){

}

void MyNoteMainWindow::insert_table(){

}

void MyNoteMainWindow::draw_brush(){

}

void MyNoteMainWindow::draw_eraser(){

}

void MyNoteMainWindow::draw_highlighter(){

}

void MyNoteMainWindow::draw_pen(){

}

void MyNoteMainWindow::format_bullet(){

}

void MyNoteMainWindow::format_font(){

}

void MyNoteMainWindow::format_group(){

}

void MyNoteMainWindow::format_highlight(){

}

void MyNoteMainWindow::format_italics(){

}

void MyNoteMainWindow::format_paragraph(){

}

void MyNoteMainWindow::format_underline(){

}

void MyNoteMainWindow::format_ungroup(){

}

void MyNoteMainWindow::help_aboutMyNote(){

}

void MyNoteMainWindow::help_license(){

}

void MyNoteMainWindow::help_usage(){

}
