#ifndef __PRINT_SNAKE_H__
#define __PRINT_SNAKE_H__

#include "config_snake.h"
#include <ncurses.h>

void imprime_borda(WINDOW *tela);

void imprime_snake(WINDOW *tela, t_lista *snake);

void imprime_comida(WINDOW *tela, t_comida *comida);

#endif