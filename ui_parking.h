/********************************************************************************
** Form generated from reading UI file 'estacionamentoEbmjPo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ESTACIONAMENTOEBMJPO_H
#define ESTACIONAMENTOEBMJPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarOne
{
public:
    QAction *actionPrint;
    QWidget *centralwidget;
    QTextEdit *placa;
    QComboBox *carro;
    QTextEdit *outro_carro;
    QLabel *label_placa;
    QLabel *label_carro;
    QLabel *label_outro;
    QPushButton *form_submit_button;
    QLabel *label_info_placa;
    QLabel *label_info_carro;
    QLabel *label_info_entrada;
    QLabel *label_info_saida;
    QLabel *label_info_tempo;
    QLabel *label_info_custo;
    QPushButton *Button_imprimir;
    QRadioButton *ingreso;
    QRadioButton *saida;
    QLabel *label_titulo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CarOne)
    {
        if (CarOne->objectName().isEmpty())
            CarOne->setObjectName(QStringLiteral("CarOne"));
        CarOne->resize(873, 653);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 180, 209, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(119, 231, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(84, 205, 232, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(25, 90, 104, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(33, 120, 139, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(152, 217, 232, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        CarOne->setPalette(palette);
        actionPrint = new QAction(CarOne);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        centralwidget = new QWidget(CarOne);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        placa = new QTextEdit(centralwidget);
        placa->setObjectName(QStringLiteral("placa"));
        placa->setGeometry(QRect(90, 120, 201, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush9(QColor(120, 120, 120, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        placa->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        placa->setFont(font);
        carro = new QComboBox(centralwidget);
        carro->setObjectName(QStringLiteral("carro"));
        carro->setGeometry(QRect(340, 120, 201, 41));
        QPalette palette2;
        QBrush brush10(QColor(52, 141, 122, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        carro->setPalette(palette2);
        carro->setFont(font);
        outro_carro = new QTextEdit(centralwidget);
        outro_carro->setObjectName(QStringLiteral("outro_carro"));
        outro_carro->setGeometry(QRect(600, 120, 201, 41));
        outro_carro->setFont(font);
        label_placa = new QLabel(centralwidget);
        label_placa->setObjectName(QStringLiteral("label_placa"));
        label_placa->setGeometry(QRect(160, 90, 61, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_placa->setFont(font1);
        label_carro = new QLabel(centralwidget);
        label_carro->setObjectName(QStringLiteral("label_carro"));
        label_carro->setGeometry(QRect(410, 90, 61, 31));
        label_carro->setFont(font1);
        label_outro = new QLabel(centralwidget);
        label_outro->setObjectName(QStringLiteral("label_outro"));
        label_outro->setGeometry(QRect(670, 90, 61, 31));
        label_outro->setFont(font1);
        form_submit_button = new QPushButton(centralwidget);
        form_submit_button->setObjectName(QStringLiteral("form_submit_button"));
        form_submit_button->setGeometry(QRect(240, 200, 181, 61));
        QPalette palette3;
        QBrush brush11(QColor(167, 0, 250, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush11);
        QBrush brush12(QColor(89, 0, 134, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        QBrush brush13(QColor(127, 0, 190, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        form_submit_button->setPalette(palette3);
        form_submit_button->setFont(font1);
        label_info_placa = new QLabel(centralwidget);
        label_info_placa->setObjectName(QStringLiteral("label_info_placa"));
        label_info_placa->setGeometry(QRect(350, 300, 331, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_info_placa->setFont(font2);
        label_info_placa->setLayoutDirection(Qt::LeftToRight);
        label_info_carro = new QLabel(centralwidget);
        label_info_carro->setObjectName(QStringLiteral("label_info_carro"));
        label_info_carro->setGeometry(QRect(340, 350, 341, 31));
        label_info_carro->setFont(font2);
        label_info_carro->setLayoutDirection(Qt::LeftToRight);
        label_info_entrada = new QLabel(centralwidget);
        label_info_entrada->setObjectName(QStringLiteral("label_info_entrada"));
        label_info_entrada->setGeometry(QRect(320, 400, 361, 31));
        label_info_entrada->setFont(font2);
        label_info_saida = new QLabel(centralwidget);
        label_info_saida->setObjectName(QStringLiteral("label_info_saida"));
        label_info_saida->setGeometry(QRect(340, 450, 341, 31));
        label_info_saida->setFont(font2);
        label_info_tempo = new QLabel(centralwidget);
        label_info_tempo->setObjectName(QStringLiteral("label_info_tempo"));
        label_info_tempo->setGeometry(QRect(270, 500, 411, 31));
        label_info_tempo->setFont(font2);
        label_info_custo = new QLabel(centralwidget);
        label_info_custo->setObjectName(QStringLiteral("label_info_custo"));
        label_info_custo->setGeometry(QRect(340, 550, 341, 31));
        label_info_custo->setFont(font2);
        Button_imprimir = new QPushButton(centralwidget);
        Button_imprimir->setObjectName(QStringLiteral("Button_imprimir"));
        Button_imprimir->setGeometry(QRect(500, 200, 181, 61));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        Button_imprimir->setFont(font3);
        ingreso = new QRadioButton(centralwidget);
        ingreso->setObjectName(QStringLiteral("ingreso"));
        ingreso->setGeometry(QRect(310, 30, 121, 51));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        ingreso->setFont(font4);
        saida = new QRadioButton(centralwidget);
        saida->setObjectName(QStringLiteral("saida"));
        saida->setGeometry(QRect(480, 30, 121, 51));
        saida->setFont(font4);
        label_titulo = new QLabel(centralwidget);
        label_titulo->setObjectName(QStringLiteral("label_titulo"));
        label_titulo->setGeometry(QRect(240, 10, 251, 41));
        label_titulo->setFont(font4);
        CarOne->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CarOne);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CarOne->setStatusBar(statusbar);

        retranslateUi(CarOne);

        QMetaObject::connectSlotsByName(CarOne);
    } // setupUi

    void retranslateUi(QMainWindow *CarOne)
    {
        CarOne->setWindowTitle(QApplication::translate("CarOne", "Estacionamento", nullptr));
        actionPrint->setText(QApplication::translate("CarOne", "Print", nullptr));
        placa->setHtml(QApplication::translate("CarOne", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        label_placa->setText(QApplication::translate("CarOne", "Placa", nullptr));
        label_carro->setText(QApplication::translate("CarOne", "Carro", nullptr));
        label_outro->setText(QApplication::translate("CarOne", "Outro", nullptr));
        form_submit_button->setText(QApplication::translate("CarOne", "Aceitar", nullptr));
        label_info_placa->setText(QApplication::translate("CarOne", "Placa:", nullptr));
        label_info_carro->setText(QApplication::translate("CarOne", "Carro:", nullptr));
        label_info_entrada->setText(QApplication::translate("CarOne", "Entrada:", nullptr));
        label_info_saida->setText(QApplication::translate("CarOne", "Saida:", nullptr));
        label_info_tempo->setText(QApplication::translate("CarOne", "Tempo total:", nullptr));
        label_info_custo->setText(QApplication::translate("CarOne", "Custo:", nullptr));
        Button_imprimir->setText(QApplication::translate("CarOne", "Imprimir", nullptr));
        ingreso->setText(QApplication::translate("CarOne", "Entrada", nullptr));
        saida->setText(QApplication::translate("CarOne", "Sa\303\255da", nullptr));
        label_titulo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CarOne: public Ui_CarOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ESTACIONAMENTOEBMJPO_H
