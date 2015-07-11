#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openButton = new QPushButton("открыть");
    treeView = new QTreeView;

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *hlayout = new QHBoxLayout;

    vlayout->addWidget(openButton);
    hlayout->addWidget(treeView);
    hlayout->addLayout(vlayout);

    ui->centralWidget->setLayout(hlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
