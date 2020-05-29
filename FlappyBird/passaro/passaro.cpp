// -- Implementação da classe do pássaro do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse4")

#include "passaro.h"

// -- Construtor --
Passaro::Passaro()
{
    _x = 15;
    _y = 15;
    _corCorpo = 9;
    _corOlho = COLOR_WHITE;
    _corBico = COLOR_RED;
    _corpo = "{v 0}=";
}

void Passaro::mover(WINDOW *t)
{
    char ch = wgetch(t);
    _y += (ch == ' ' ? -1 : GRAVIDADE);
}

int Passaro::getX()
{
    return _x;
}

int Passaro::getY()
{
    return _y;
}

int Passaro::getcorCorpo()
{
    return _corCorpo;
}

int Passaro::getcorOlho()
{
    return _corOlho;
}

int Passaro::getcorBico()
{
    return _corBico;
}

string Passaro::getCorpo()
{
    return _corpo;
}
