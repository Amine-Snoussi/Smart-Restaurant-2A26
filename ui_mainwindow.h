/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGroupBox *groupBox_13;
    QPushButton *pushButton_7;
    QLineEdit *le_adresse_2;
    QLabel *label_45;
    QLineEdit *le_email_2;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLineEdit *le_tel_2;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLineEdit *prenom_modif_5;
    QLineEdit *nom_modif_4;
    QSpinBox *sb_codePostal_2;
    QDateTimeEdit *le_dateReservation_3;
    QLineEdit *le_ville_2;
    QLabel *label_52;
    QLabel *label_53;
    QLineEdit *id_client_modif_3;
    QWidget *tab_8;
    QGroupBox *groupBox_9;
    QPushButton *button_modifierReservation_3;
    QLabel *label_36;
    QLineEdit *nom_modif;
    QLabel *label_37;
    QLabel *label_38;
    QLineEdit *id_client_modif;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLineEdit *le_ville_modif;
    QLabel *label_54;
    QLabel *label_55;
    QLineEdit *prenom_modif_2;
    QSpinBox *sb_codePostal_modif;
    QLineEdit *le_adresse_modif;
    QLineEdit *le_email_modif;
    QLineEdit *le_tel_modif;
    QGroupBox *groupBox_10;
    QPushButton *button_supprimerReservation_3;
    QLineEdit *lineEdit_20;
    QLabel *label_42;
    QGroupBox *groupBox_11;
    QTableView *tabClient;
    QLineEdit *lineEdit_21;
    QComboBox *cb_colone_3;
    QPushButton *pushButton_8;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QPushButton *pushButton;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QPushButton *button_modifierReservation;
    QLabel *label_9;
    QDateEdit *dateEdit_2;
    QLabel *label_13;
    QLabel *label_10;
    QSpinBox *spinBox_3;
    QLabel *label_8;
    QSpinBox *spinBox_4;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QTimeEdit *timeEdit_2;
    QLineEdit *lineEdit_6;
    QGroupBox *groupBox_2;
    QPushButton *button_supprimerReservation;
    QLabel *label_14;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox_3;
    QTableView *tabReservation;
    QLineEdit *lineEdit_4;
    QComboBox *cb_colone;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuReservation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(797, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(14, 9, 771, 531));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_3 = new QTabWidget(tab);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, 0, 791, 541));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tab_7->setAutoFillBackground(false);
        groupBox_13 = new QGroupBox(tab_7);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(0, 0, 751, 471));
        pushButton_7 = new QPushButton(groupBox_13);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(600, 430, 93, 28));
        le_adresse_2 = new QLineEdit(groupBox_13);
        le_adresse_2->setObjectName(QStringLiteral("le_adresse_2"));
        le_adresse_2->setGeometry(QRect(190, 270, 211, 22));
        label_45 = new QLabel(groupBox_13);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(20, 210, 55, 21));
        le_email_2 = new QLineEdit(groupBox_13);
        le_email_2->setObjectName(QStringLiteral("le_email_2"));
        le_email_2->setGeometry(QRect(190, 210, 211, 22));
        label_46 = new QLabel(groupBox_13);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(20, 330, 55, 16));
        label_47 = new QLabel(groupBox_13);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(480, 30, 61, 20));
        label_48 = new QLabel(groupBox_13);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(20, 150, 171, 20));
        le_tel_2 = new QLineEdit(groupBox_13);
        le_tel_2->setObjectName(QStringLiteral("le_tel_2"));
        le_tel_2->setGeometry(QRect(540, 30, 191, 22));
        label_49 = new QLabel(groupBox_13);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(420, 400, 141, 16));
        label_50 = new QLabel(groupBox_13);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(20, 30, 131, 16));
        label_51 = new QLabel(groupBox_13);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(20, 400, 91, 16));
        prenom_modif_5 = new QLineEdit(groupBox_13);
        prenom_modif_5->setObjectName(QStringLiteral("prenom_modif_5"));
        prenom_modif_5->setGeometry(QRect(190, 150, 211, 22));
        prenom_modif_5->setReadOnly(false);
        nom_modif_4 = new QLineEdit(groupBox_13);
        nom_modif_4->setObjectName(QStringLiteral("nom_modif_4"));
        nom_modif_4->setGeometry(QRect(190, 80, 211, 22));
        nom_modif_4->setReadOnly(false);
        sb_codePostal_2 = new QSpinBox(groupBox_13);
        sb_codePostal_2->setObjectName(QStringLiteral("sb_codePostal_2"));
        sb_codePostal_2->setGeometry(QRect(190, 400, 211, 22));
        sb_codePostal_2->setMinimum(0);
        sb_codePostal_2->setMaximum(9999);
        sb_codePostal_2->setValue(0);
        le_dateReservation_3 = new QDateTimeEdit(groupBox_13);
        le_dateReservation_3->setObjectName(QStringLiteral("le_dateReservation_3"));
        le_dateReservation_3->setGeometry(QRect(560, 400, 131, 22));
        le_ville_2 = new QLineEdit(groupBox_13);
        le_ville_2->setObjectName(QStringLiteral("le_ville_2"));
        le_ville_2->setGeometry(QRect(190, 330, 211, 22));
        label_52 = new QLabel(groupBox_13);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(20, 270, 55, 16));
        label_53 = new QLabel(groupBox_13);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(20, 70, 131, 41));
        id_client_modif_3 = new QLineEdit(groupBox_13);
        id_client_modif_3->setObjectName(QStringLiteral("id_client_modif_3"));
        id_client_modif_3->setEnabled(false);
        id_client_modif_3->setGeometry(QRect(190, 30, 211, 22));
        id_client_modif_3->setReadOnly(true);
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        groupBox_9 = new QGroupBox(tab_8);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 0, 471, 221));
        button_modifierReservation_3 = new QPushButton(groupBox_9);
        button_modifierReservation_3->setObjectName(QStringLiteral("button_modifierReservation_3"));
        button_modifierReservation_3->setGeometry(QRect(390, 190, 71, 21));
        label_36 = new QLabel(groupBox_9);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(210, 10, 131, 41));
        nom_modif = new QLineEdit(groupBox_9);
        nom_modif->setObjectName(QStringLiteral("nom_modif"));
        nom_modif->setGeometry(QRect(250, 20, 211, 22));
        nom_modif->setReadOnly(false);
        label_37 = new QLabel(groupBox_9);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(200, 80, 55, 21));
        label_38 = new QLabel(groupBox_9);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(190, 50, 171, 20));
        id_client_modif = new QLineEdit(groupBox_9);
        id_client_modif->setObjectName(QStringLiteral("id_client_modif"));
        id_client_modif->setGeometry(QRect(80, 20, 121, 22));
        id_client_modif->setReadOnly(false);
        label_39 = new QLabel(groupBox_9);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(10, 60, 91, 16));
        label_40 = new QLabel(groupBox_9);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(10, 100, 61, 20));
        label_41 = new QLabel(groupBox_9);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(190, 110, 55, 16));
        le_ville_modif = new QLineEdit(groupBox_9);
        le_ville_modif->setObjectName(QStringLiteral("le_ville_modif"));
        le_ville_modif->setGeometry(QRect(250, 140, 211, 22));
        label_54 = new QLabel(groupBox_9);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(20, 20, 131, 16));
        label_55 = new QLabel(groupBox_9);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(210, 140, 55, 16));
        prenom_modif_2 = new QLineEdit(groupBox_9);
        prenom_modif_2->setObjectName(QStringLiteral("prenom_modif_2"));
        prenom_modif_2->setGeometry(QRect(250, 50, 211, 22));
        prenom_modif_2->setReadOnly(false);
        sb_codePostal_modif = new QSpinBox(groupBox_9);
        sb_codePostal_modif->setObjectName(QStringLiteral("sb_codePostal_modif"));
        sb_codePostal_modif->setGeometry(QRect(90, 60, 71, 22));
        sb_codePostal_modif->setMinimum(0);
        sb_codePostal_modif->setMaximum(9999);
        sb_codePostal_modif->setValue(0);
        le_adresse_modif = new QLineEdit(groupBox_9);
        le_adresse_modif->setObjectName(QStringLiteral("le_adresse_modif"));
        le_adresse_modif->setGeometry(QRect(250, 110, 211, 22));
        le_email_modif = new QLineEdit(groupBox_9);
        le_email_modif->setObjectName(QStringLiteral("le_email_modif"));
        le_email_modif->setGeometry(QRect(250, 80, 211, 22));
        le_tel_modif = new QLineEdit(groupBox_9);
        le_tel_modif->setObjectName(QStringLiteral("le_tel_modif"));
        le_tel_modif->setGeometry(QRect(10, 130, 191, 22));
        groupBox_10 = new QGroupBox(tab_8);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(490, 0, 261, 221));
        button_supprimerReservation_3 = new QPushButton(groupBox_10);
        button_supprimerReservation_3->setObjectName(QStringLiteral("button_supprimerReservation_3"));
        button_supprimerReservation_3->setGeometry(QRect(180, 80, 71, 20));
        lineEdit_20 = new QLineEdit(groupBox_10);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(140, 30, 113, 22));
        label_42 = new QLabel(groupBox_10);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(20, 30, 91, 16));
        groupBox_11 = new QGroupBox(tab_8);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(9, 229, 741, 211));
        tabClient = new QTableView(groupBox_11);
        tabClient->setObjectName(QStringLiteral("tabClient"));
        tabClient->setGeometry(QRect(10, 50, 721, 151));
        tabClient->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabClient->setSortingEnabled(true);
        lineEdit_21 = new QLineEdit(groupBox_11);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setGeometry(QRect(660, 20, 71, 22));
        cb_colone_3 = new QComboBox(groupBox_11);
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->addItem(QString());
        cb_colone_3->setObjectName(QStringLiteral("cb_colone_3"));
        cb_colone_3->setGeometry(QRect(580, 20, 61, 22));
        pushButton_8 = new QPushButton(tab_8);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(610, 440, 131, 31));
        tabWidget_3->addTab(tab_8, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 791, 541));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setAutoFillBackground(false);
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 91, 16));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 81, 16));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 170, 91, 16));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 240, 141, 16));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 300, 55, 16));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 360, 55, 16));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 420, 55, 16));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(150, 10, 113, 22));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 90, 113, 22));
        spinBox = new QSpinBox(tab_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(220, 170, 42, 22));
        spinBox_2 = new QSpinBox(tab_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(220, 240, 42, 22));
        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 300, 113, 22));
        dateEdit = new QDateEdit(tab_3);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 360, 110, 22));
        timeEdit = new QTimeEdit(tab_3);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(150, 420, 118, 22));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 440, 93, 28));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, -1, 251, 251));
        button_modifierReservation = new QPushButton(groupBox);
        button_modifierReservation->setObjectName(QStringLiteral("button_modifierReservation"));
        button_modifierReservation->setGeometry(QRect(170, 220, 71, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 120, 141, 16));
        dateEdit_2 = new QDateEdit(groupBox);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(130, 150, 110, 22));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 60, 81, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 90, 91, 16));
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(200, 90, 42, 22));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 30, 91, 16));
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(200, 120, 42, 22));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 180, 55, 16));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 150, 55, 16));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 30, 113, 22));
        timeEdit_2 = new QTimeEdit(groupBox);
        timeEdit_2->setObjectName(QStringLiteral("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(130, 180, 111, 22));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(130, 60, 113, 22));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 0, 491, 51));
        button_supprimerReservation = new QPushButton(groupBox_2);
        button_supprimerReservation->setObjectName(QStringLiteral("button_supprimerReservation"));
        button_supprimerReservation->setGeometry(QRect(280, 20, 71, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 20, 91, 16));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(130, 20, 113, 22));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 250, 751, 201));
        tabReservation = new QTableView(groupBox_3);
        tabReservation->setObjectName(QStringLiteral("tabReservation"));
        tabReservation->setGeometry(QRect(10, 40, 731, 151));
        tabReservation->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabReservation->setSortingEnabled(true);
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(600, 10, 71, 22));
        cb_colone = new QComboBox(groupBox_3);
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->addItem(QString());
        cb_colone->setObjectName(QStringLiteral("cb_colone"));
        cb_colone->setGeometry(QRect(530, 10, 61, 22));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(630, 450, 131, 31));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 450, 121, 28));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 50, 491, 201));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 797, 26));
        menuReservation = new QMenu(menubar);
        menuReservation->setObjectName(QStringLiteral("menuReservation"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuReservation->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Client", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "Email :", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "Ville :", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "T\303\251l :", nullptr));
        label_48->setText(QApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "Date_de_r\303\251servation :", nullptr));
        label_50->setText(QApplication::translate("MainWindow", "Id_client:", nullptr));
        label_51->setText(QApplication::translate("MainWindow", "Code postal :", nullptr));
        label_52->setText(QApplication::translate("MainWindow", "Adresse :", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "Nom :", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "Ajouter un Client", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Modifier Les Donn\303\251es Des Clients", nullptr));
        button_modifierReservation_3->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "Nom :", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "Email :", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "Code postal :", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "T\303\251l :", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "Adresse :", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "Id_client", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "Ville :", nullptr));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Supprimer Un Client", nullptr));
        button_supprimerReservation_3->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "id_client:", nullptr));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Affichage des clients", nullptr));
        lineEdit_21->setPlaceholderText(QApplication::translate("MainWindow", "recherche", nullptr));
        cb_colone_3->setItemText(0, QApplication::translate("MainWindow", "Tous", nullptr));
        cb_colone_3->setItemText(1, QApplication::translate("MainWindow", "Nom de l'entreprise", nullptr));
        cb_colone_3->setItemText(2, QApplication::translate("MainWindow", "Description", nullptr));
        cb_colone_3->setItemText(3, QApplication::translate("MainWindow", "Matricule fiscale", nullptr));
        cb_colone_3->setItemText(4, QApplication::translate("MainWindow", "Email", nullptr));
        cb_colone_3->setItemText(5, QApplication::translate("MainWindow", "Adresse", nullptr));
        cb_colone_3->setItemText(6, QApplication::translate("MainWindow", "Ville", nullptr));
        cb_colone_3->setItemText(7, QApplication::translate("MainWindow", "Code postal", nullptr));
        cb_colone_3->setItemText(8, QApplication::translate("MainWindow", "Tel", nullptr));
        cb_colone_3->setItemText(9, QApplication::translate("MainWindow", "Fax", nullptr));
        cb_colone_3->setItemText(10, QApplication::translate("MainWindow", "Total d'achats", nullptr));

        pushButton_8->setText(QApplication::translate("MainWindow", "Retour", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "Afficher les Clients", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Gestion de Clients", nullptr));
        label->setText(QApplication::translate("MainWindow", "id_reservation:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "id_client:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Num Du Table:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Nombre de personnes:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Ville:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Date:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Heure:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Ajouter une Reservation", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Modifier Une Reservation", nullptr));
        button_modifierReservation->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Nombre de personnes:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "id_client:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Num Du Table:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "id_reservation:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Heure:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Date:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Supprimer Une Reservation", nullptr));
        button_supprimerReservation->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "id_reservation:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Affichage des Donn\303\251es des  reservations", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "recherche", nullptr));
        cb_colone->setItemText(0, QApplication::translate("MainWindow", "Tous", nullptr));
        cb_colone->setItemText(1, QApplication::translate("MainWindow", "Nom de l'entreprise", nullptr));
        cb_colone->setItemText(2, QApplication::translate("MainWindow", "Description", nullptr));
        cb_colone->setItemText(3, QApplication::translate("MainWindow", "Matricule fiscale", nullptr));
        cb_colone->setItemText(4, QApplication::translate("MainWindow", "Email", nullptr));
        cb_colone->setItemText(5, QApplication::translate("MainWindow", "Adresse", nullptr));
        cb_colone->setItemText(6, QApplication::translate("MainWindow", "Ville", nullptr));
        cb_colone->setItemText(7, QApplication::translate("MainWindow", "Code postal", nullptr));
        cb_colone->setItemText(8, QApplication::translate("MainWindow", "Tel", nullptr));
        cb_colone->setItemText(9, QApplication::translate("MainWindow", "Fax", nullptr));
        cb_colone->setItemText(10, QApplication::translate("MainWindow", "Total d'achats", nullptr));

        pushButton_3->setText(QApplication::translate("MainWindow", "Retour", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Confimation Mail", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Statistique", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Afficher les Reservations", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Gestion de Reservations", nullptr));
        menuReservation->setTitle(QApplication::translate("MainWindow", "Gestion De Clients Et Reservations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
