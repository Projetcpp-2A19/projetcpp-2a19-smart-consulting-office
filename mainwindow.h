#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtableview.h"
#include <QMainWindow>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QTimer>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStyledItemDelegate>
#include <QTableView>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCharts>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

namespace Ui {
class MainWindow;
}

class TrackingDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadData();

    int currentlySelectedRow;
    QString getPriorityText(int priorityValue);  // Already exists
    int getPriorityValue(const QString &priorityText);
    QStringList getPriorityOptions();

private slots:
    void on_addButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_sortComboBox_currentIndexChanged(int index);
    void on_exportButton_clicked();
    void showTrackingContextMenu(const QPoint &pos);
    void markProjectCompleted();
    void changeProjectPriority();
    void updateGanttChart();
    void changeProjectStatus(const QString &newStatus);


private:
    Ui::MainWindow *ui;
    QSqlQueryModel *employeModel;
    QSqlQueryModel *clientModel;
    QSqlQueryModel *trackingModel;
    QTableView *trackingTableView;
    QChartView *chartView;
    QGraphicsScene *ganttScene;

    void updateProjectView();
    void exportTableToPDF();
    void loadEmployes();
    void loadClients();
    void setupTrackingTable();
    void updateTrackingView();
    QColor getPriorityColor(int priority) const;
    void setupCharts();
    void updateProgressChart();
    void playSuccessSound();
    void updateStatusChart();    // Builds the chart
     void addTimelineHeader(int yPos);

    void initializeGanttScene();

     void drawMonthHeader(const QDate &today, int dayWidth, int yPos);
     void drawWeekHeader(const QDate &today, int dayWidth, int yPos);

     // Project drawing
     void drawProjectRow(int x, int y, int width,
                         const QString &name,
                         const QDate &startDate,
                         const QDate &endDate,
                         int priority);
     void drawDateMarker(int x, int y, const QDate &date, const QString &label);

     // Visual elements
     void drawTodayMarker(const QDate &today, int dayWidth, int bottomY);
     QColor getPriorityColor(int priority);

     // View adjustment
     void adjustViewToContent(int contentHeight);
     void drawSimplifiedDayHeader(const QDate &today, int dayWidth, int yPos);


};

#endif // MAINWINDOW_H
