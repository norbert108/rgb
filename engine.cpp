#include "engine.h"

Engine::Engine(int wys, int szer, QObject *parent) : QObject(parent)
{
    wysokosc = wys;
    szerokosc = szer;

}

// Settery
void Engine::setRozmiar(QSize size)
{
    if((wysokosc == size.height())&&(szerokosc == size.width()))
    {
        return;
    }

    wysokosc = size.height();
    szerokosc = size.width();

    emit zmianaRozmiaru(wysokosc,szerokosc);
}

// Gettery
int Engine::readSzerokosc()
{
    return szerokosc;
}

int Engine::readWysokosc()
{
    return wysokosc;
}

