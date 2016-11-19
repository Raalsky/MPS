#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile File(":/assets/layout.css");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    this->setStyleSheet(StyleSheet);

    //ui->statusBar->showMessage("Offline");

    QTreeWidget * tree = ui->treeWidget;

    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, "This is top level");

    for(int i=0; i<5; i++)
    {
        QTreeWidgetItem * item = new QTreeWidgetItem();
        item->setText(0,"item " + QString::number(i+1));
        topLevel->addChild(item);
    }

    tree->addTopLevelItem(topLevel);

    QPixmap img(":/assets/online.png");
    QLabel *label = new QLabel(this);
    label->setPixmap(img);
    QLabel *status = new QLabel(this);
    status->setText("Online");

    ui->statusBar->addWidget(label);
    ui->statusBar->addWidget(status);
}

MainWindow::~MainWindow()
{
    delete ui;
}
