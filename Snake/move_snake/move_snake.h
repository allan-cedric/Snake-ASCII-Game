#ifndef __MOVE_SNAKE_H__
#define __MOVE_SNAKE_H__

#include <ncurses.h>
#include <ctype.h>
#include "lista_dupla_snake.h"

void move_snake(int k, int w, t_lista *snake);

void direcao (int *k, int *w, int tecla);

#endif