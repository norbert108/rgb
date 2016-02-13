#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Wybierz obraz do wczytania."), "",  "", 0, 0);
    image = QImage(fileName);
    original_image = image.copy();

    if(image.isNull())
    {
        QMessageBox::critical(this, "Nieobsługiwany format pliku", "Wybrany plik nie zawiera obrazu w obsługiwanym formacie", NULL, NULL);

        return;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_actionZapisz_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz obraz");
    image.save(fileName);
}
