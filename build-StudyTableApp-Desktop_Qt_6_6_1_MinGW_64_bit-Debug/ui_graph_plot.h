/********************************************************************************
** Form generated from reading UI file 'graph_plot.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_PLOT_H
#define UI_GRAPH_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_graph_plot
{
public:

    void setupUi(QDialog *graph_plot)
    {
        if (graph_plot->objectName().isEmpty())
            graph_plot->setObjectName("graph_plot");
        graph_plot->resize(566, 496);

        retranslateUi(graph_plot);

        QMetaObject::connectSlotsByName(graph_plot);
    } // setupUi

    void retranslateUi(QDialog *graph_plot)
    {
        graph_plot->setWindowTitle(QCoreApplication::translate("graph_plot", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_plot: public Ui_graph_plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_PLOT_H
