#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    styleButton();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_openFile_clicked()
{
    openFile();
}

void MainWindow::on_actionOpen_File_triggered()
{
    openFile();
}

void MainWindow::openFile()
{
    pathFile = QFileDialog::getOpenFileName(this, "Open File", "C:\\", "*.txt;; *.doc");
    fileText.setFileName(pathFile);
    if (fileText.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->te_setText->setText(fileText.readAll());
        ui->statusbar->showMessage("File open successfully : " + pathFile);
    } else {
        QMessageBox::warning(this, "Error open file", pathFile + "File not open");
        ui->statusbar->showMessage("Error open file");
        qDebug() << "Error open file";
    }
    fileText.close();
    ui->lb_info->setText("File " + pathFile + " open successfully");
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::saveFile(QString pathFile)
{
    fileText.setFileName(pathFile);
    if (fileText.open(QIODevice::WriteOnly)) {
        QTextStream out(&fileText);
        out << ui->te_setText->toPlainText();
        ui->statusbar->showMessage("File " + pathFile + " save successfully");
    } else {
        QMessageBox::warning(this, "Error Save File", "Error Save File" + pathFile);
        ui->statusbar->showMessage("File " + pathFile + " not save");
    }
    fileText.close();
    ui->lb_info->setText("File " + pathFile + " save successfully");
}

void MainWindow::on_pb_saveFile_clicked()
{
    saveFile(pathFile);
}

void MainWindow::on_actionSave_triggered()
{
    saveFile(pathFile);
}

void MainWindow::on_pb_saveAsFile_clicked()
{
    pathFile = QFileDialog::getSaveFileName(this, "SaveAs File", "C:\\", "*.txt;; *.doc");
    saveFile(pathFile);
}

void MainWindow::on_actionSaveAs_File_triggered()
{
    pathFile = QFileDialog::getSaveFileName(this, "SaveAs File", "C:\\", "*.txt;; *.doc");
    saveFile(pathFile);
}

void MainWindow::on_actionClear_All_triggered()
{
    ui->te_setText->clear();
}

void MainWindow::on_pb_findWord_clicked()
{
    findWord();
}

void MainWindow::on_actionFind_Word_triggered()
{
    findWord();
}

void MainWindow::findWord()
{
    QList<QTextEdit::ExtraSelection> sel;
    ui->te_setText->moveCursor(QTextCursor::Start);
    QString findWord = ui->le_findWord->text();
    while(ui->te_setText->find(findWord))
        {
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(QColor(Qt::green).lighter(125));
            extra.cursor = ui->te_setText->textCursor();
            sel.append(extra);
        }
    ui->te_setText->setExtraSelections(sel);
    ui->te_setText->moveCursor(QTextCursor::End);
    ui->le_findWord->clear();
}

void MainWindow::styleButton()
{
    this->setStyleSheet("background-color: #999;");
    ui->pb_openFile->setStyleSheet(Style::getStyleButtons());
    ui->pb_saveFile->setStyleSheet(Style::getStyleButtons());
    ui->pb_saveAsFile->setStyleSheet(Style::getStyleButtons());
    ui->pb_replace->setStyleSheet(Style::getStyleButtons());
    ui->pb_findWord->setStyleSheet(Style::getStyleButtons());
}
