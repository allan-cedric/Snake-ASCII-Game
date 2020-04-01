#ifndef __COLLISION_SNAKE_H__
#define __COLLISION_SNAKE_H__

#include "config_snake.h"
#include "lista_dupla_snake.h"

int acertou_barreira(t_lista *snake);

int acertou_cobra(t_lista *snake);

int acertou_comida (t_lista *snake, t_comida *comida) ;

void ingere_comida (t_lista *snake, int k, int w) ;

#endif