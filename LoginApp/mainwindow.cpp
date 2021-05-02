#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_LOGIN_clicked()
{
    QString username = ui->lineEdit_username->text();
       QString password = ui->lineEdit_password->text();

       if(username == "open" && password == "openx")
       {
           QMessageBox::information(this, "Login", "Username and Password is correct");
           secDialog = new SecDialog(this);
           secDialog->show();
       }
       else
       {
           QMessageBox::warning(this, "Login", "Username and Password is incorrect");
       }
}
