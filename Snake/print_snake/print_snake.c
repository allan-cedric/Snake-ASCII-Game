#include "print_snake.h"

void imprime_borda(WINDOW *tela)
{
    int i;
    for (i = 0; i <= MAX_Y; i++)
    {
        mvwaddch(tela, i, 0, 0);
        mvwaddch(tela, i, MAX_X, 0);
    }
    for (i = 0; i <= MAX_X; i++)
    {
        mvwaddch(tela, 0, i, 0);
        mvwaddch(tela, MAX_Y, i, 0);
    }
}

void imprime_snake(WINDOW *tela, t_lista *snake)
{
    inicializa_atual_inicio(snake);
    while (snake->atual != snake->fim)
    {
        mvwaddch(tela, snake->atual->i, snake->atual->j, 0);
        incrementa_atual(snake);
    }
}

void imprime_comida(WINDOW *tela, t_comida *comida)
{
    mvwaddch(tela, comida->i, comida->j, 0);
}