#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QSize>

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(int wys, int szer, QObject *parent = 0);
    int readWysokosc();
    int readSzerokosc();

private:
    int wysokosc;
    int szerokosc;

signals:
    void zmianaRozmiaru(int,int);

public slots:
    void setRozmiar(QSize);
};

#endif // ENGINE_H
