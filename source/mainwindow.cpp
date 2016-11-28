#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include "process.h"


Prio prio;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    prio.addProcess(1);
    prio.addProcess(2);
    prio.addProcess(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Add Process
void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Adding Process");
    msgBox.setText("Please select a priority for the process to be added");
    msgBox.setInformativeText("A new process will be created with a random process 'time'");
    QPushButton *hp = msgBox.addButton(tr("High Priority"), QMessageBox::ActionRole);
    QPushButton *mp = msgBox.addButton(tr("Medium Priority"), QMessageBox::ActionRole);
    QPushButton *lp = msgBox.addButton(tr("Low Priority"), QMessageBox::ActionRole);

    msgBox.exec();

    if (msgBox.clickedButton() == hp)
        prio.addProcess(1);
    else if (msgBox.clickedButton() == mp)
        prio.addProcess(2);
    else if (msgBox.clickedButton() == lp)
        prio.addProcess(3);
}

//Context Switch
void MainWindow::on_pushButton_2_clicked()
{
    prio.setProcess();

    prio.printState();
}

//Block Process
void MainWindow::on_pushButton_4_clicked()
{
    prio.blockProcess();


}


void MainWindow::on_pushButton_5_clicked()
{
    prio.unblockProcess();
}






void MainWindow::on_pushButton_6_clicked()
{
    prio.printState();
}


