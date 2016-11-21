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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *search;
    QListWidget *searchResults;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *details;
    QListWidget *listWidget_3;
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
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        search = new QLineEdit(tab);
        search->setObjectName(QStringLiteral("search"));

        verticalLayout_2->addWidget(search);

        searchResults = new QListWidget(tab);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        new QListWidgetItem(searchResults);
        searchResults->setObjectName(QStringLiteral("searchResults"));

        verticalLayout_2->addWidget(searchResults);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        details = new QTableWidget(groupBox);
        if (details->columnCount() < 1)
            details->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        details->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (details->rowCount() < 7)
            details->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        details->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        details->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        details->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        details->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        details->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        details->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        details->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        details->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        details->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        details->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        details->setItem(3, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        details->setItem(4, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        details->setItem(5, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        details->setItem(6, 0, __qtablewidgetitem14);
        details->setObjectName(QStringLiteral("details"));

        horizontalLayout_3->addWidget(details);

        listWidget_3 = new QListWidget(groupBox);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));

        horizontalLayout_3->addWidget(listWidget_3);


        verticalLayout_2->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_2);

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

        const bool __sortingEnabled = searchResults->isSortingEnabled();
        searchResults->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = searchResults->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem1 = searchResults->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem2 = searchResults->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem3 = searchResults->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem4 = searchResults->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem5 = searchResults->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem6 = searchResults->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem7 = searchResults->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem8 = searchResults->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem9 = searchResults->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem10 = searchResults->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindow", "dr hab. Rafa\305\202 Jankowski Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego w Krakowie", 0));
        QListWidgetItem *___qlistwidgetitem11 = searchResults->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem12 = searchResults->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        QListWidgetItem *___qlistwidgetitem13 = searchResults->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MainWindow", "prof. dr. hab. Adrianna Ewa Jasi\305\204ska-Jankowska lekraz weterynarii Wydzia\305\202 Lekarski Collegium Medicum Uniwersytetu Jagiello\305\204skiego", 0));
        searchResults->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("MainWindow", "Dane pacjenta", 0));
        QTableWidgetItem *___qtablewidgetitem = details->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Pacjent", 0));
        QTableWidgetItem *___qtablewidgetitem1 = details->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Imi\304\231", 0));
        QTableWidgetItem *___qtablewidgetitem2 = details->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Nazwisko", 0));
        QTableWidgetItem *___qtablewidgetitem3 = details->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Pesel", 0));
        QTableWidgetItem *___qtablewidgetitem4 = details->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Data urodzenia", 0));
        QTableWidgetItem *___qtablewidgetitem5 = details->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Termin ubezpieczenia", 0));
        QTableWidgetItem *___qtablewidgetitem6 = details->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Ostatnia wizyta", 0));
        QTableWidgetItem *___qtablewidgetitem7 = details->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Jakies inne dziwne dane", 0));

        const bool __sortingEnabled1 = details->isSortingEnabled();
        details->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = details->item(0, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Rafa\305\202", 0));
        QTableWidgetItem *___qtablewidgetitem9 = details->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Jankowski", 0));
        QTableWidgetItem *___qtablewidgetitem10 = details->item(2, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "96042112444", 0));
        QTableWidgetItem *___qtablewidgetitem11 = details->item(3, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "21 Kwietnia 1996", 0));
        QTableWidgetItem *___qtablewidgetitem12 = details->item(4, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "15-04-2020", 0));
        QTableWidgetItem *___qtablewidgetitem13 = details->item(5, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "10-11-2015", 0));
        QTableWidgetItem *___qtablewidgetitem14 = details->item(6, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Dane", 0));
        details->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Pacjenci", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Pracownicy", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Apteki", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
