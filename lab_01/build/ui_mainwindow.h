/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *actionOpen;
    QPushButton *button_Turn;
    QLineEdit *lineEdit_TurnX;
    QLineEdit *lineEdit_TurnY;
    QLineEdit *lineEdit_TurnZ;
    QLabel *label_TurnX;
    QLabel *label_TurnY;
    QLabel *label_TurnZ;
    QPushButton *button_Scale;
    QLineEdit *lineEdit_ScaleX;
    QLineEdit *lineEdit_ScaleY;
    QLineEdit *lineEdit_ScaleZ;
    QLabel *label_ScaleZ;
    QLabel *label_ScaleY;
    QLabel *label_ScaleX;
    QPushButton *button_Move;
    QLineEdit *lineEdit_MoveZ;
    QLineEdit *lineEdit_MoveY;
    QLineEdit *lineEdit_MoveX;
    QLabel *label_MoveY;
    QLabel *label_MoveZ;
    QLabel *label_MoveX;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1272, 665);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 821, 631));
        actionOpen = new QPushButton(centralWidget);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setGeometry(QRect(1000, 20, 111, 31));
        QFont font;
        font.setPointSize(12);
        actionOpen->setFont(font);
        button_Turn = new QPushButton(centralWidget);
        button_Turn->setObjectName(QString::fromUtf8("button_Turn"));
        button_Turn->setGeometry(QRect(930, 560, 251, 31));
        button_Turn->setFont(font);
        lineEdit_TurnX = new QLineEdit(centralWidget);
        lineEdit_TurnX->setObjectName(QString::fromUtf8("lineEdit_TurnX"));
        lineEdit_TurnX->setGeometry(QRect(930, 520, 70, 20));
        lineEdit_TurnY = new QLineEdit(centralWidget);
        lineEdit_TurnY->setObjectName(QString::fromUtf8("lineEdit_TurnY"));
        lineEdit_TurnY->setGeometry(QRect(1020, 520, 70, 20));
        lineEdit_TurnZ = new QLineEdit(centralWidget);
        lineEdit_TurnZ->setObjectName(QString::fromUtf8("lineEdit_TurnZ"));
        lineEdit_TurnZ->setGeometry(QRect(1110, 520, 70, 20));
        label_TurnX = new QLabel(centralWidget);
        label_TurnX->setObjectName(QString::fromUtf8("label_TurnX"));
        label_TurnX->setGeometry(QRect(930, 490, 45, 21));
        QFont font1;
        font1.setPointSize(11);
        label_TurnX->setFont(font1);
        label_TurnY = new QLabel(centralWidget);
        label_TurnY->setObjectName(QString::fromUtf8("label_TurnY"));
        label_TurnY->setGeometry(QRect(1020, 490, 45, 21));
        label_TurnY->setFont(font1);
        label_TurnZ = new QLabel(centralWidget);
        label_TurnZ->setObjectName(QString::fromUtf8("label_TurnZ"));
        label_TurnZ->setGeometry(QRect(1110, 490, 45, 21));
        label_TurnZ->setFont(font1);
        button_Scale = new QPushButton(centralWidget);
        button_Scale->setObjectName(QString::fromUtf8("button_Scale"));
        button_Scale->setGeometry(QRect(930, 370, 251, 31));
        button_Scale->setFont(font);
        lineEdit_ScaleX = new QLineEdit(centralWidget);
        lineEdit_ScaleX->setObjectName(QString::fromUtf8("lineEdit_ScaleX"));
        lineEdit_ScaleX->setGeometry(QRect(930, 330, 70, 20));
        lineEdit_ScaleY = new QLineEdit(centralWidget);
        lineEdit_ScaleY->setObjectName(QString::fromUtf8("lineEdit_ScaleY"));
        lineEdit_ScaleY->setGeometry(QRect(1020, 330, 70, 20));
        lineEdit_ScaleZ = new QLineEdit(centralWidget);
        lineEdit_ScaleZ->setObjectName(QString::fromUtf8("lineEdit_ScaleZ"));
        lineEdit_ScaleZ->setGeometry(QRect(1110, 330, 70, 20));
        label_ScaleZ = new QLabel(centralWidget);
        label_ScaleZ->setObjectName(QString::fromUtf8("label_ScaleZ"));
        label_ScaleZ->setGeometry(QRect(1110, 300, 45, 21));
        label_ScaleZ->setFont(font1);
        label_ScaleY = new QLabel(centralWidget);
        label_ScaleY->setObjectName(QString::fromUtf8("label_ScaleY"));
        label_ScaleY->setGeometry(QRect(1020, 300, 45, 21));
        label_ScaleY->setFont(font1);
        label_ScaleX = new QLabel(centralWidget);
        label_ScaleX->setObjectName(QString::fromUtf8("label_ScaleX"));
        label_ScaleX->setGeometry(QRect(930, 300, 45, 21));
        label_ScaleX->setFont(font1);
        button_Move = new QPushButton(centralWidget);
        button_Move->setObjectName(QString::fromUtf8("button_Move"));
        button_Move->setGeometry(QRect(930, 180, 251, 31));
        button_Move->setFont(font);
        lineEdit_MoveZ = new QLineEdit(centralWidget);
        lineEdit_MoveZ->setObjectName(QString::fromUtf8("lineEdit_MoveZ"));
        lineEdit_MoveZ->setGeometry(QRect(1110, 140, 70, 20));
        lineEdit_MoveY = new QLineEdit(centralWidget);
        lineEdit_MoveY->setObjectName(QString::fromUtf8("lineEdit_MoveY"));
        lineEdit_MoveY->setGeometry(QRect(1020, 140, 70, 20));
        lineEdit_MoveX = new QLineEdit(centralWidget);
        lineEdit_MoveX->setObjectName(QString::fromUtf8("lineEdit_MoveX"));
        lineEdit_MoveX->setGeometry(QRect(930, 140, 70, 20));
        label_MoveY = new QLabel(centralWidget);
        label_MoveY->setObjectName(QString::fromUtf8("label_MoveY"));
        label_MoveY->setGeometry(QRect(1020, 110, 45, 21));
        label_MoveY->setFont(font1);
        label_MoveZ = new QLabel(centralWidget);
        label_MoveZ->setObjectName(QString::fromUtf8("label_MoveZ"));
        label_MoveZ->setGeometry(QRect(1110, 110, 45, 21));
        label_MoveZ->setFont(font1);
        label_MoveX = new QLabel(centralWidget);
        label_MoveX->setObjectName(QString::fromUtf8("label_MoveX"));
        label_MoveX->setGeometry(QRect(930, 110, 45, 21));
        label_MoveX->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1030, 80, 61, 21));
        QFont font2;
        font2.setPointSize(14);
        font2.setUnderline(true);
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1030, 270, 61, 21));
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1030, 460, 51, 21));
        label_3->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\236\320\236\320\237 3D \320\232\320\260\321\200\320\272\320\260\321\201", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        button_Turn->setText(QCoreApplication::translate("MainWindow", "Turn", nullptr));
        lineEdit_TurnX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_TurnY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_TurnZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_TurnX->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        label_TurnY->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        label_TurnZ->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        button_Scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        lineEdit_ScaleX->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEdit_ScaleY->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEdit_ScaleZ->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_ScaleZ->setText(QCoreApplication::translate("MainWindow", "kz:", nullptr));
        label_ScaleY->setText(QCoreApplication::translate("MainWindow", "ky:", nullptr));
        label_ScaleX->setText(QCoreApplication::translate("MainWindow", "kx:", nullptr));
        button_Move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        lineEdit_MoveZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_MoveY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_MoveX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_MoveY->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        label_MoveZ->setText(QCoreApplication::translate("MainWindow", "dz:", nullptr));
        label_MoveX->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
