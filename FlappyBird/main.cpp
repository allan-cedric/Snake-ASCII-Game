// -- Programa principal para o jogo (Flappy Bird) --
// -- Autor: Allan Cedric --

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse4")

// -- Bibliotecas --
#include <unistd.h>
#include "cenario/cenario.h"

// -- Macros para tela do jogo--
#define COLUNAS(x) (x / 3 + 20)
#define LINHAS(y) (y - 2)

#define X0(x) (x / 3 - 10)
#define Y0 1

// -- Função de setup dos recursos da ncurses --
void inicia_ncurses()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
}

// -- Variáveis globais --
int estado = 0, tempo = 0;
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

    init_pair(2, COLOR_WHITE, cenario.getcorChao());
    init_pair(3, cenario.getcorChao(), cenario.getcorChao());

    init_color(cenario.getcorSolo(), 999, 800, 400);
    init_pair(4, cenario.getcorSolo(), cenario.getcorSolo());

    // -- Jogo --
    while (1)
    {
        // -- Impressão do cenário (Sem os canos) --
        if (!(tempo % cenario.gettempoMovimentacao()))
        {
            werase(tela_jogo);
            for (int j = 0; j < COLUNAS(x); j++)
            {
                if (!estado)
                {
                    wattron(tela_jogo, COLOR_PAIR(2));
                    mvwaddch(tela_jogo, LINHAS(y) - 9, j, '/');
                    wattroff(tela_jogo, COLOR_PAIR(2));
                }
                else
                {
                    wattron(tela_jogo, COLOR_PAIR(3));
                    mvwaddch(tela_jogo, LINHAS(y) - 9, j, '/');
                    wattroff(tela_jogo, COLOR_PAIR(3));
                }
                estado = !estado;
            }
            for (int i = LINHAS(y) - 8; i < LINHAS(y); i++)
            {
                for (int j = 0; j < COLUNAS(x); j++)
                {
                    wattron(tela_jogo, COLOR_PAIR(4));
                    mvwaddch(tela_jogo, i, j, '.');
                    wattroff(tela_jogo, COLOR_PAIR(4));
                }
            }
            if (estado)
                estado = 0;
            else
                estado = 1;
        }

        // -- Manipulação do tempo do jogo --
        tempo++;
        wrefresh(tela_jogo);
        usleep(10000);
    }

    return 0;
}
