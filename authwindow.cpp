#include "authwindow.h"
#include "ui_authwindow.h"
#include <QMessageBox>
AuthWindow::AuthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_pushButton_clicked()
{
    if(ui->lgn->text() == LOGIN && ui->psw->text() == PASSWORD){
        QMessageBox::information(this, "authorization", "success");
        accept();
    }
    else
        QMessageBox::information(this, "authorization", "failed");
}

