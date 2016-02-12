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
    img.scaled((wys),(szer));
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "/home");
    QPixmap image(fileName);
    pix = image;

    QImage tmp =image.toImage();
    img = tmp;

    //ui->label->setPixmap(image);
    //ui->label->setScaledContents(this); // aaaaaaaa działa

    QSize size = this->size();
    //QResizeEvent size2 = this->size();

     int wys = size.height();
     int szer = size.width();
     img.scaled((wys/2),(szer/2));//?
     ui->label->setPixmap(QPixmap::fromImage(img));


}
