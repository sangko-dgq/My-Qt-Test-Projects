#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void sg_sendLoginSuccess();

private slots:
    void on_btn_login_clicked();
    void on_btn_exit_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
