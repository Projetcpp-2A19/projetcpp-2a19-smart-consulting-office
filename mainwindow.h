#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_addClient_clicked();
    void on_pushButton_deleteClient_clicked();
    void on_pushButton_updateClient_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_pdf_clicked();
    void on_pushButton_notify_clicked();
    void on_lineEdit_searchEmail_textChanged(const QString &arg1);
    void on_pushButton_sortByName_clicked();
    void on_pushButton_sortByCin_clicked();
    void on_pushButton_actualiser_clicked();
    void on_pushButton_statistique_clicked();
    void on_pushButton_backup_clicked();


private:
    int m_currentClientId;
    bool m_editMode;

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
