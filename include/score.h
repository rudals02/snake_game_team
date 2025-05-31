#ifndef SCORE_H
#define SCORE_H

#include "physics.h"
#include <stdlib.h>

extern int score;
//뱀이 사과를 먹었는지 1->먹음 0->안먹음
int Snake_eat_apple(position snakeHead, Size apple);

//먹은 사과의 크기에 따라 점수 증가. 크기 1당 10
void increase_score();

#endif
