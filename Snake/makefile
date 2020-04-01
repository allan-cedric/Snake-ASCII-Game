CC=gcc
CFLAGS=-ansi -Wall
LDLIBS=-lncurses -lm

EXEC=snake
SNAKEOBJ=snake.o config_snake.o print_snake.o move_snake.o collision_snake.o lista_dupla_snake.o

all:snake clean

snake: $(SNAKEOBJ)
	$(CC) $(SNAKEOBJ) -o snake $(CFLAGS) $(LDLIBS)

snake.o: snake.c config_snake.h print_snake.h move_snake.h collision_snake.h lista_dupla_snake.h
	$(CC) -c snake.c $(CCFLAGS)

config_snake.o: config_snake.c config_snake.h 
	$(CC) -c config_snake.c $(CFLAGS) 

print_snake.o: print_snake.c print_snake.h 
	$(CC) -c print_snake.c $(CFLAGS)
 
move_snake.o: move_snake.c move_snake.h 
	$(CC) -c move_snake.c $(CFLAGS) 

collision_snake.o: collision_snake.c collision_snake.h 
	$(CC) -c collision_snake.c $(CFLAGS)
 
lista_dupla_snake.o: lista_dupla_snake.c lista_dupla_snake.h 
	$(CC) -c lista_dupla_snake.c $(CFLAGS)

clean:
	-rm -f $(SNAKEOBJ) *~

purge: clean
	-rm -f $(EXEC) 
