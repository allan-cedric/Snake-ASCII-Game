// -- Implementação da classe do cano do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#include "canos.h"

Cano::Cano()
{
    _y = 0;
    _y_passagem = 0;
    _x = 80;
}

void Cano::mover()
{
    _x--;
}

int Cano::getY()
{
    return _y;
}

int Cano::getX()
{
    return _x;
}

int Cano::getYPassagem()
{
    return _y_passagem;
}

void Cano::resetX()
{
    _x = 80;
}

void Cano::gerayPassagem()
{
    _y_passagem = (rand() % 15) + 3;
}