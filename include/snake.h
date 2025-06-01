#ifndef SNAKE_H
#define SNAKE_H

#include "physics.h"

typedef enum { UP, DOWN, LEFT, RIGHT } direction;

extern position snake[];
extern int snake_length;
extern int gameover;
extern Size apple;

void init_snake(void);
void move_snake(void);
void grow_snake(int size);
void draw_snake(void);
void draw_apple(void);
void set_direction(direction dir);

#endif
