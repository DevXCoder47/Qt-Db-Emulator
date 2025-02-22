#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "authwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(new dbmanagement::DbManager())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_authButton_clicked()
{
    AuthWindow window;
    window.setModal(true);
    if(window.exec() == QDialog::Accepted) {
        ui->authButton->setEnabled(false);
        ui->dbTable->setEnabled(true);
        ui->queryEdit->setEnabled(true);
        ui->connButton->setEnabled(true);
        ui->dbNameEdit->setEnabled(true);
    }
}

void MainWindow::executeQueries() {
    QString query = ui->queryEdit->toPlainText().trimmed();
    QString firstWord = query.section(' ', 0, 0).toUpper();
    QSqlQuery* sqlQuery = manager->executeQuery(query);
    if(firstWord == "SELECT"){
        manager->renderResultInConsole(sqlQuery);
        manager->renderResultInTable(sqlQuery, ui->dbTable);
        ui->statusbar->showMessage("selection query executed");
    }
    else
        ui->statusbar->showMessage("modifying query executed");
}

void MainWindow::on_execButton_clicked()
{
    executeQueries();
}

void MainWindow::on_connButton_clicked()
{
    manager->manageDatabase(ui->dbNameEdit->text());
    ui->dconnButton->setEnabled(true);
    ui->execButton->setEnabled(true);
    ui->connButton->setEnabled(false);
}


void MainWindow::on_dconnButton_clicked()
{
    manager->closeConnection();
    ui->connButton->setEnabled(true);
    ui->dconnButton->setEnabled(false);
    ui->execButton->setEnabled(false);
}

