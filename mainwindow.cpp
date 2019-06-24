#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    /* Only allow room name to be alphanumeric inc. underscore, starting with letter */
    ui->settingsRoomName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z][A-Za-z0-9_]+")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_2_stateChanged(int state)
{
    printf("state: %i\n", state);
    ui->roomEditorCanvas->setGridShown((state==2) ? true : false);
}
