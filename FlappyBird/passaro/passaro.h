// -- Classe do pássaro do jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma once

// -- Bibliotecas --
#include <ncurses.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// -- Macros --
#define GRAVIDADE 1

// -- Class Passaro --
class Passaro
{
private:
    int _x;
    int _y;
    int _corCorpo;
    int _corOlho;
    int _corBico;
    string _corpo;
public:
    Passaro(); // Construtor
    void mover(WINDOW *t);
    int getX();
    int getY();
    int getcorCorpo();
    int getcorOlho();
    int getcorBico();
    string getCorpo();
};