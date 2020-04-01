#include "lib_snake.h"

int main()
{
    srand(time(NULL));

    int tecla;
    int k, w;

    /* Direção que a cobra irá começar */
    k = (rand() % 3) - 1;
    if (k != 0)
        w = 0;
    else
        w = 1;

    /* Inicialização das estruturas */
    t_lista snake;
    t_comida comida;
    inicializa_estruturas(&snake, &comida);

    /* Configurações da 'ncurses */
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);

    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(3));

    while (1)
    {
        werase(stdscr);

        /* Impressão dos elementos do jogo */
        wattron(stdscr, COLOR_PAIR(1));
        imprime_borda(stdscr);
        wattroff(stdscr, COLOR_PAIR(1));

        wattron(stdscr, COLOR_PAIR(2));
        imprime_snake(stdscr, &snake);
        imprime_comida(stdscr, &comida);
        wattroff(stdscr, COLOR_PAIR(2));

        /* Colisão Snake-Comida */
        if (acertou_comida(&snake, &comida))
            ingere_comida(&snake, k, w);

        if (!comida.estado)
            sorteia_comida(&snake, &comida);

        /* Colisão Snake-NãoComida */
        if (acertou_barreira(&snake))
            break;
        else if (acertou_cobra(&snake))
            break;

        /* Movimentação Snake */
        tecla = wgetch(stdscr);
        if (tecla != 'q')
            direcao(&k, &w, tecla);
        else
            break;
        move_snake(k, w, &snake);

        usleep(47000);
    }
    destroi_lista(&snake);
    endwin();

    return 0;
}