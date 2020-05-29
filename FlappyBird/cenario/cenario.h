// -- Classe do cenário do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

// -- Bibliotecas --
#pragma once

#include <ncurses.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// -- Classe Cenario --
class Cenario
{
private:
    int _corFundo;
    int _corSolo;
    int _corChao;
    int _tempoMovimentacao;

public:
    Cenario(); // Construtor
    int getcorFundo();
    int getcorSolo();
    int getcorChao();
    int gettempoMovimentacao();
};