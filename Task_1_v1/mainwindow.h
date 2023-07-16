#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>
#include <QTextList>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "style.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_openFile_clicked();
    void openFile();
    void on_actionOpen_File_triggered();
    void on_actionSave_triggered();
    void on_pb_saveFile_clicked();
    void saveFile(QString pathFile);

    void on_pb_saveAsFile_clicked();
    void on_actionSaveAs_File_triggered();

    void on_actionClear_All_triggered();

    void on_pb_findWord_clicked();
    void on_actionFind_Word_triggered();
    void findWord();

    void styleButton();

    void on_actionExit_triggered();



private:
    Ui::MainWindow *ui;
    QString pathFile;
    QFile fileText;

};
#endif // MAINWINDOW_H
