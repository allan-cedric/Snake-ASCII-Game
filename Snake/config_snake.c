#include "config_snake.h"

void inicializa_estruturas(t_lista *snake, t_comida *comida)
{
    int k;
    inicializa_lista(snake);
    for (k = 0; k < TAM_INICIAL; k++)
        insere_fim_lista(I_INICIAL, J_INICIAL - k, snake);

    sorteia_comida(snake, comida);
}

void sorteia_comida(t_lista *snake, t_comida *comida)
{
    comida->estado = 1 ;
    do
    {
        comida->i = (rand() % 35) + 2;
        comida->j = (rand() % 96) + 2;
        comida->estado = 1;
    } while (pertence_lista(comida->i, comida->j, snake));
}