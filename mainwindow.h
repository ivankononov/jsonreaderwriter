#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "json.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeView>
#include <QFileDialog>
#include <QFile>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *openButton;
    QTreeView *treeView;
    QLabel *label;
private slots:
    void openJsonFile();
};

#endif // MAINWINDOW_H
