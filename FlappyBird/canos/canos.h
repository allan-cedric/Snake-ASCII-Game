// -- Implementação classe do cano do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma once

// -- Bibliotecas --
#include <ncurses.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// -- Macros --
#define CANO_LINHAS 30
#define CANO_COLUNAS 10
#define LINHAS_PASSAGEM 8

// -- Classe Cano --
class Cano
{
private:
    int _y;
    int _y_passagem;
    int _x;

public:
    Cano(); // Construtor
    void mover();
    int getY();
    int getX();
    int getYPassagem();
    void resetX();
    void gerayPassagem();
};