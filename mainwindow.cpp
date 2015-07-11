#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openButton = new QPushButton("открыть");
    treeView = new QTreeView;
    label = new QLabel;

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *hlayout = new QHBoxLayout;

    vlayout->addWidget(openButton);
    vlayout->addWidget(label);

    hlayout->addWidget(treeView);
    hlayout->addLayout(vlayout);

    ui->centralWidget->setLayout(hlayout);

    connect(openButton, SIGNAL(clicked(bool)), this, SLOT(openJsonFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openJsonFile()
{
    QString path = QFileDialog::getOpenFileName();
    QFile jsonFile(path);
    jsonFile.open(QFile::ReadOnly);
    label->setText(jsonFile.readAll());
    bool ok;
    QtJson::JsonObject obj = QtJson::parse(jsonFile.readAll(), ok).toMap();


}

