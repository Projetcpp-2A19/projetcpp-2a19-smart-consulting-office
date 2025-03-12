#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>  // Required for QModelIndex usage

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadData();

    int getPriorityValue(const QString &priorityText);
    QString getPriorityText(int priorityValue);

private slots:
    void on_addButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
