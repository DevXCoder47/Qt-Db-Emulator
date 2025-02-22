#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AuthWindow *ui;
    const char* LOGIN = "login";
    const char* PASSWORD = "password";
};

#endif // AUTHWINDOW_H
