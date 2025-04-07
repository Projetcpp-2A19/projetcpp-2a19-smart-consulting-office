#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  <QSqlTableModel>
#include  <QSortFilterProxyModel>
#include  <QString>
#include  <QFileDialog>
#include  <QPdfWriter>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include  <QVBoxLayout>


#include "consultant.h"



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


    void on_QJOUTERCONSULTQNTBUTTON_clicked();



    void on_supprierconsultqntpushbutton_clicked();


    void on_odifyconsultant_clicked();

    void on_consultantTable_clicked(const QModelIndex &index);
    void on_searchConsultantByTyping(const QString &searchText);



    void on_tricroiradiobutton_clicked();

    void on_tridecroiradiobutton_clicked();

    void on_exportpdfbutton_clicked();

    void on_statistiquepushbutton_clicked();

    void on_hidepushbutton_clicked();

private:
    void initializeConsultantTableModel() ;

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *consultantModel;
    QSqlTableModel*consultantTableModel;


    QSortFilterProxyModel* consultantProxyModel;

};
#endif // MAINWINDOW_H
