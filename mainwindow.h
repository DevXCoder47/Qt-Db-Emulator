#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_authButton_clicked();

    void on_execButton_clicked();

    void on_connButton_clicked();

    void on_dconnButton_clicked();

private:
    Ui::MainWindow *ui;
    dbmanagement::DbManager* manager;
    void executeQueries();
};
#endif // MAINWINDOW_H
