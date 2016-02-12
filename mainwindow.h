#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QCloseEvent>
#include <QPixmap>
#include <QResizeEvent>

#include "engine.h"

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
    QPixmap pix;
    QImage img;

private slots:
    void on_pushButton_clicked();
    void resizeImage(int,int);

private:
    Ui::MainWindow *ui;
    Engine *engine;
};

#endif // MAINWINDOW_H
