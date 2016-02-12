#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSize size = this->size();
    int h = size.height();
    int w = size.width();

    engine = new Engine(h,w,this);

    connect(this,SIGNAL(iconSizeChanged(QSize)),//?
            engine,SLOT(setRozmiar(QSize)));//?

    //connect(this,SIGNAL(iconSizeChanged(QSize)),//?
          //  engine,SLOT(setRozmiar(QSize)));//?

    connect(engine,SIGNAL(zmianaRozmiaru(int,int)),
            this,SLOT(resizeImage(int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeImage(int wys, int szer)
{
//    img.scaled((wys),(szer));
//    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_actionOdcienie_szaro_ci_triggered()
{
    for (int i = 0; i < image.width(); i++)
    {
        for (int j=0; j < image.height(); j++)
        {
            int gray = qGray(image.pixel(i, j));
            image.setPixel(i, j, qRgb(gray, gray, gray));
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_actionOryginalny_triggered()
{
    image = original_image.copy();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_actionOdwr_cone_triggered()
{
    image.invertPixels();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_actionOtw_rz_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Wybierz obraz do wczytania."), "",  "Supported files (*.png)", 0, 0);
    image = QImage(fileName);
    original_image = image.copy();

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_actionZapisz_triggered()
{
    QString fileName = QFileDialog::getSaveFileName();
    image.save(fileName);
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    image = original_image.scaled(ui->label->width(), ui->label->height());
    ui->label->setPixmap(QPixmap::fromImage(image));
}
