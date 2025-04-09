#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QTimer>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>

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
    void on_searchLineEdit_textChanged(const QString &text);
    void on_sortComboBox_currentIndexChanged(int index);
    void on_exportButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *employeModel;
    QSqlQueryModel *clientModel;
    void updateProjectView();
    void exportTableToPDF();
    void loadEmployes();
    void loadClients();
};

#endif // MAINWINDOW_H
