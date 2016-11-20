/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *main;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QLineEdit *search;
    QGridLayout *gridLayout_2;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QWidget *tab_2;
    QWidget *tab_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 621);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        main = new QWidget(MainWindow);
        main->setObjectName(QStringLiteral("main"));
        main->setEnabled(true);
        main->setMinimumSize(QSize(800, 600));
        gridLayout = new QGridLayout(main);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(main);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(13213123, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        search = new QLineEdit(tab);
        search->setObjectName(QStringLiteral("search"));

        verticalLayout->addWidget(search);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame1 = new QFrame(tab);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(frame1);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        gridLayout_2->addWidget(frame1, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(main);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral(""));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MedicalPrescriptionsSystem Client", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Pracownicy", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Pacjenci", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Apteki", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
