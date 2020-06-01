// -- Implementação classe dos canos do jogo (Flappy Bird) --
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
#define CANO_COLUNAS 5
#define LINHAS_PASSAGEM 5

// -- Classe Canos --
class Canos
{
private:
    vector<int> _y;
    vector<int> _x;
    vector<int> _y_passagem;
    vector<int> _x_passagem;

public:
    Canos(); // Construtor
    void geraCano();
};