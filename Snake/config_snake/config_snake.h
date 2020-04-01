#ifndef __CONFIG_SNAKE_H__
#define __CONFIG_SNAKE_H__

#include "lista_dupla_snake.h"
#include <time.h>

/* Configuração de tela */
#define MAX_Y 38
#define MAX_X 100

/* Configuração inicial da cobra */
#define TAM_INICIAL 4 
#define I_INICIAL 19
#define J_INICIAL 50

struct t_comida
{
    int i, j;
    int estado;
};
typedef struct t_comida t_comida;

void inicializa_estruturas(t_lista *snake, t_comida *comida);

void sorteia_comida(t_lista *snake, t_comida *comida);

#endif