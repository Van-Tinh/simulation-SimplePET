/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *Cancel;
    QPushButton *Ok;
    QPushButton *Apply;
    QLabel *label_11;
    QFrame *line;
    QLabel *label_12;
    QPushButton *Applyroot;
    QLineEdit *showhelpanderror;
    QPushButton *appl;
    QLineEdit *nameoutput;
    QLineEdit *lineEdit;
    QLineEdit *AxisX;
    QLineEdit *AxisY;
    QLineEdit *Axisrotation;
    QLineEdit *Fanrotation;
    QLineEdit *Timeslice;
    QLabel *label_13;
    QLabel *sinogram;
    QLabel *image;
    QLineEdit *lineEdit_2;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(736, 368);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 121, 17));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 151, 17));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 30, 101, 17));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 60, 101, 17));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 90, 81, 17));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 260, 67, 17));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 20, 161, 17));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 230, 67, 17));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(290, 90, 81, 17));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 130, 121, 17));
        Cancel = new QPushButton(Widget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(630, 320, 89, 25));
        Ok = new QPushButton(Widget);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(190, 300, 61, 25));
        Apply = new QPushButton(Widget);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(120, 300, 71, 25));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 90, 111, 17));
        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(269, 0, 17, 331));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(290, 50, 131, 17));
        Applyroot = new QPushButton(Widget);
        Applyroot->setObjectName(QString::fromUtf8("Applyroot"));
        Applyroot->setGeometry(QRect(660, 50, 71, 25));
        showhelpanderror = new QLineEdit(Widget);
        showhelpanderror->setObjectName(QString::fromUtf8("showhelpanderror"));
        showhelpanderror->setGeometry(QRect(280, 260, 441, 51));
        appl = new QPushButton(Widget);
        appl->setObjectName(QString::fromUtf8("appl"));
        appl->setGeometry(QRect(530, 320, 89, 25));
        nameoutput = new QLineEdit(Widget);
        nameoutput->setObjectName(QString::fromUtf8("nameoutput"));
        nameoutput->setGeometry(QRect(142, 170, 131, 25));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 130, 131, 25));
        AxisX = new QLineEdit(Widget);
        AxisX->setObjectName(QString::fromUtf8("AxisX"));
        AxisX->setGeometry(QRect(110, 230, 111, 25));
        AxisY = new QLineEdit(Widget);
        AxisY->setObjectName(QString::fromUtf8("AxisY"));
        AxisY->setGeometry(QRect(110, 260, 111, 25));
        Axisrotation = new QLineEdit(Widget);
        Axisrotation->setObjectName(QString::fromUtf8("Axisrotation"));
        Axisrotation->setGeometry(QRect(160, 20, 91, 25));
        Fanrotation = new QLineEdit(Widget);
        Fanrotation->setObjectName(QString::fromUtf8("Fanrotation"));
        Fanrotation->setGeometry(QRect(160, 50, 91, 25));
        Timeslice = new QLineEdit(Widget);
        Timeslice->setObjectName(QString::fromUtf8("Timeslice"));
        Timeslice->setGeometry(QRect(160, 80, 91, 25));
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 170, 131, 20));
        sinogram = new QLabel(Widget);
        sinogram->setObjectName(QString::fromUtf8("sinogram"));
        sinogram->setGeometry(QRect(300, 120, 161, 121));
        image = new QLabel(Widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(510, 120, 171, 121));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(410, 50, 241, 25));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(630, 0, 101, 23));

        retranslateUi(Widget);
        QObject::connect(Cancel, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Position Sources", nullptr));
        label_2->setText(QApplication::translate("Widget", "Parameter sources ", nullptr));
        label_3->setText(QApplication::translate("Widget", "Axis Rottion :", nullptr));
        label_4->setText(QApplication::translate("Widget", "Fan Rotation :", nullptr));
        label_5->setText(QApplication::translate("Widget", "Time Slice :", nullptr));
        label_6->setText(QApplication::translate("Widget", "Axis Y", nullptr));
        label_7->setText(QApplication::translate("Widget", "Image Recontruction: ", nullptr));
        label_8->setText(QApplication::translate("Widget", "Axis X", nullptr));
        label_9->setText(QApplication::translate("Widget", "Sinogram", nullptr));
        label_10->setText(QApplication::translate("Widget", "Sources Activity:", nullptr));
        Cancel->setText(QApplication::translate("Widget", "Cancel", nullptr));
        Ok->setText(QApplication::translate("Widget", "OK", nullptr));
        Apply->setText(QApplication::translate("Widget", "Apply", nullptr));
        label_11->setText(QApplication::translate("Widget", "Recontruction: ", nullptr));
        label_12->setText(QApplication::translate("Widget", "File Ouput.root :", nullptr));
        Applyroot->setText(QApplication::translate("Widget", "Browser", nullptr));
        appl->setText(QApplication::translate("Widget", "apply", nullptr));
        label_13->setText(QApplication::translate("Widget", "Name file output:", nullptr));
        sinogram->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        image->setText(QApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
