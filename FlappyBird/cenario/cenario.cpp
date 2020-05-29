// -- Implementação da classe do cenário do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse4")

#include "cenario.h"

// -- Construtor --
Cenario::Cenario()
{
    _corFundo = COLOR_CYAN;
    _corSolo = COLOR_YELLOW;
    _corChao = COLOR_GREEN;
}

int Cenario::getcorFundo()
{
    return _corFundo;
}

int Cenario::getcorSolo()
{
    return _corSolo;
}

int Cenario::getcorChao()
{
    return _corChao;
}