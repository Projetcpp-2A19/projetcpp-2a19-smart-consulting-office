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
#include "arduino.h"

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
    void on_connectArduino_clicked();
    void on_setThreshold_clicked();
    void updateTemperature();



    void on_add_button_4_clicked();

    void on_modifStadeButton_4_clicked();

    void on_DeleteStadeButton_4_clicked();

    void on_trier_Button_4_clicked();

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_tableViewEmploye_4_doubleClicked(const QModelIndex &index);

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

void initializeSpecialityComboBox();
    void displaySpecialiteStats() ;

void on_menu_employe_clicked();

    void on_employe_go_to_menu_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *employeModel;
    QSqlQueryModel *clientModel;
    QSqlQueryModel *trackingModel;
    QTableView *trackingTableView;
    QChartView *chartView;
    QGraphicsScene *ganttScene;
    Arduino arduino;
    QTimer *temperatureTimer;
    float currentThreshold;
    int currentProjectId;

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


     //gestion employe
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
