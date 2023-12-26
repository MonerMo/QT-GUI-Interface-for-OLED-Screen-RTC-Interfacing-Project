#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>

unsigned char slots_values[3] = {0 , 0 , 0} ;
float total_value[3] {0.0 , 0.0 , 0.0};
int hours_values[3] {0 , 0 , 0};
int minutes_values[3] {0 , 0 , 0};
unsigned char button_clicked = false ;


void value_modulator(){
    for(int i = 0 ; i < 3 ; i++){
        float hours = ((slots_values[i] & 0b11100000 ) >> 5 );
        hours += ((slots_values[i] & 0b00011111) / 60.0 );
        total_value[i] = hours;
    }
}

void on_each_own(){
    for(int i = 0 ; i < 3 ; i++){
        int hours = ((slots_values[i] & 0b11100000) >> 5);
        int minutes = (slots_values[i] & 0b00011111);
        hours_values[i] = hours ;
        minutes_values[i] = minutes ;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //reading mins and hours studied for the 3 slots
    QFile file(":/resources/text/studyhour.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning","file not open");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    unsigned char index = 0 ;
    for(int i = 1 ; i <=8 ; i+=4){
        unsigned char digit = 0 ;
        unsigned char lsb = text[i].digitValue() ;
        digit |= (lsb << 5 );
        unsigned char msb = text[i+1].digitValue();
        digit |= (msb);
        slots_values[index] = digit ;
        index++;
    }

    //now we will calculate percentage and total minutes and hours for each slot
    value_modulator();
    on_each_own();

    //Gui image , label and line edit configurations
    ui->statusbar->hide();
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    QPixmap bg(":/resources/img/background.jpg");
    ui->label_pic->setPixmap(bg.scaled(w,h,Qt::KeepAspectRatio));

        std::string slot_0_total = "ARM " + std::to_string(hours_values[0]) + "h " +
                         std::to_string(minutes_values[0]) + "m" ;

        std::string slot_1_total = "Embedded Linux " + std::to_string(hours_values[1]) + "h " +
                         std::to_string(minutes_values[1]) + "m" ;


        std::string slot_2_total = "Coding " + std::to_string(hours_values[2]) + "h " +
                         std::to_string(minutes_values[2]) + "m" ;


        QString slot_0_string = QString::fromStdString(slot_0_total);
        QString slot_1_string = QString::fromStdString(slot_1_total);
        QString slot_2_string = QString::fromStdString(slot_2_total);



        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);
        series->append(slot_0_string,total_value[0]);
        series->append(slot_1_string,total_value[1]);
        series->append(slot_2_string,total_value[2]);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle("test");

        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->graph_frame);


}

MainWindow::~MainWindow()
{
    delete ui;
}







