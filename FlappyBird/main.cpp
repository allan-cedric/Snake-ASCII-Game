// -- Programa principal para o jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse4")

// -- Bibliotecas --
#include <unistd.h>
#include "cenario/cenario.h"
#include "passaro/passaro.h"

// -- Macros para tela do jogo--
#define COLUNAS(x) (x / 3 + 20)
#define LINHAS(y) (y - 2)

#define X0(x) (x / 3 - 10)
#define Y0 1

// -- Protótipos das funções --
void inicia_ncurses();
void imprime_cenario(WINDOW *t);
void imprime_passaro(WINDOW *t, Passaro p);

// -- Variáveis globais --
int tempo = 0;
int x, y;

// -- Programa principal --
int main()
{
    // -- Setup da tela do jogo--
    inicia_ncurses();
    getmaxyx(stdscr, y, x);
    WINDOW *tela_jogo = newwin(LINHAS(y), COLUNAS(x), Y0, X0(x));

    // -- Setup do cenário --
    Cenario cenario;
    init_pair(1, cenario.getcorFundo(), cenario.getcorFundo());
    wbkgd(tela_jogo, COLOR_PAIR(1));

    init_color(COLOR_WHITE, 999, 999, 999);
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(2, COLOR_WHITE, cenario.getcorChao());
    init_pair(3, cenario.getcorChao(), cenario.getcorChao());

    init_color(cenario.getcorSolo(), 999, 800, 400);
    init_pair(4, cenario.getcorSolo(), cenario.getcorSolo());

    Passaro passaro;
    init_color(passaro.getcorCorpo(), 999, 999, 0);
    init_pair(5, COLOR_BLACK, passaro.getcorCorpo());
    init_pair(6, COLOR_BLACK, passaro.getcorOlho());
    init_pair(7, passaro.getcorBico(), COLOR_CYAN);

    // -- Jogo --
    while (1)
    {
        // -- Impressão do cenário (Sem os canos) --
        if (!(tempo % cenario.gettempoMovimentacao()))
            imprime_cenario(tela_jogo);

        imprime_passaro(tela_jogo, passaro);

        // -- Manipulação do tempo do jogo --
        tempo++;
        wrefresh(tela_jogo);
        usleep(10000);
    }

    return 0;
}

// -- Função de setup dos recursos da ncurses --
void inicia_ncurses()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
}

// -- Função que imprime o cenário do jogo (Sem pipes) --
void imprime_cenario(WINDOW *t)
{
    static int estado = 0;
    werase(t);
    // Chão
    for (int j = 0; j < COLUNAS(x); j++)
    {
        wattron(t, COLOR_PAIR(2 + estado));
        mvwaddch(t, LINHAS(y) - 9, j, '/');
        wattroff(t, COLOR_PAIR(2 + estado));
        estado = !estado;
    }
    // Solo
    for (int i = LINHAS(y) - 8; i < LINHAS(y); i++)
    {
        for (int j = 0; j < COLUNAS(x); j++)
        {
            wattron(t, COLOR_PAIR(4));
            mvwaddch(t, i, j, '.');
            wattroff(t, COLOR_PAIR(4));
        }
    }
    estado = !estado;
}

void imprime_passaro(WINDOW *t, Passaro p)
{
    for (int i = 0; i < p.getCorpo().length(); i++)
    {
        switch (p.getCorpo()[i])
        {
        case '0':
            wattron(t, COLOR_PAIR(6));
            mvwaddch(t, p.getY(), p.getX() + i, p.getCorpo()[i]);
            wattroff(t, COLOR_PAIR(6));
            break;
        case '=':
            wattron(t, COLOR_PAIR(7));
            mvwaddch(t, p.getY(), p.getX() + i, p.getCorpo()[i]);
            wattroff(t, COLOR_PAIR(7));
            break;
        default:
            wattron(t, COLOR_PAIR(5));
            mvwaddch(t, p.getY(), p.getX() + i, p.getCorpo()[i]);
            wattroff(t, COLOR_PAIR(5));
        }
    }
}
