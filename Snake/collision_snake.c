#include "collision_snake.h"

int acertou_barreira(t_lista *snake)
{
    if (snake->ini->prox->i >= MAX_Y || snake->ini->prox->i <= 0)
        return 1;
    else if (snake->ini->prox->j >= MAX_X - 1 || snake->ini->prox->j <= 1)
        return 1;
    return 0;
}

int acertou_cobra(t_lista *snake)
{
    inicializa_atual_inicio(snake);
    incrementa_atual(snake);
    while (snake->atual != snake->fim)
    {
        if (snake->atual->i == snake->ini->prox->i && snake->atual->j == snake->ini->prox->j)
            return 1;
        incrementa_atual(snake);
    }
    return 0;
}

int acertou_comida(t_lista *snake, t_comida *comida)
{
    if (snake->ini->prox->i == comida->i && snake->ini->prox->j == comida->j)
    {
        comida->estado = 0;
        return 1;
    }
    return 0;
}

void ingere_comida(t_lista *snake, int k, int w)
{
    insere_inicio_lista((snake->ini->prox->i) + k, (snake->ini->prox->j) + w, snake);
}