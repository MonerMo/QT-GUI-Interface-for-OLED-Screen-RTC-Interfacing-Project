#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <bits/stdc++.h>

#include <QMainWindow>
#include <QPixmap>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>


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
    void on_graph_plot_clicked();

    void on_graph_plot_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
