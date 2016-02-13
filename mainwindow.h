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
#include <QMessageBox>

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
    QImage image;
    QImage original_image;

private slots:

    void on_actionOdcienie_szaro_ci_triggered();

    void on_actionOryginalny_triggered();

    void on_actionOdwr_cone_triggered();

    void on_actionOtw_rz_triggered();

    void on_actionZapisz_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
