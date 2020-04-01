#include "move_snake.h"

void move_snake(int k, int w, t_lista *snake)
{
    remove_fim_lista(snake);
    insere_inicio_lista(k + (snake->ini->prox->i), w + (snake->ini->prox->j), snake);
}

void direcao(int *k, int *w, int tecla)
{
    tecla = tolower(tecla);
    if ((tecla == 'd' || tecla == KEY_RIGHT) && *k)
    {
        *k = 0;
        *w = 1;
    }
    else if ((tecla == 'a' || tecla == KEY_LEFT) && *k)
    {
        *k = 0;
        *w = -1;
    }
    else if ((tecla == 'w' || tecla == KEY_UP) && *w)
    {
        *k = -1;
        *w = 0;
    }
    else if ((tecla == 's' || tecla == KEY_DOWN) && *w)
    {
        *k = 1;
        *w = 0;
    }    
}
