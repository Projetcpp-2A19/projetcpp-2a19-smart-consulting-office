#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "arduino.h"

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


    void on_add_button_clicked();

    void on_modifStadeButton_clicked();

    void on_DeleteStadeButton_clicked();



    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_trier_Button_clicked();

    void on_tableViewEmploye_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();
    void initializeSpecialityComboBox();
    void displaySpecialiteStats();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
    int currentUserId;
    QString currentUserName;
    QString currentUserRole;
    QString generateVerificationCode();
    bool sendResetEmail(const QString &email, const QString &name, const QString &code);
    void loginFailed();
    void showPasswordChangeNotification();

    Arduino A;
    QTimer* Atimer;
};
#endif // MAINWINDOW_H
