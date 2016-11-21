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

    QPixmap img(":/assets/online.png");
    QLabel *label = new QLabel(this);
    label->setPixmap(img);
    QLabel *status = new QLabel(this);
    status->setText("Online");

    ui->statusBar->addWidget(label);
    ui->statusBar->addWidget(status);

    ui->search->setAttribute(Qt::WA_MacShowFocusRect, 0);

    ui->searchResults->setFocusPolicy(Qt::NoFocus);

    QHeaderView* header = ui->details->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}
