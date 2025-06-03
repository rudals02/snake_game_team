#include "score.h"
#include <stdio.h>

int score = 0;


//뱀이 사과와 닿으면 1
int Snake_eat_apple(position snakeHead, Size apple) 
{
     return (snakeHead.x >= apple.pos.x - apple.size && snakeHead.x <= apple.pos.x + apple.size &&
        snakeHead.y >= apple.pos.y - apple.size && snakeHead.y <= apple.pos.y + apple.size);
}

extern position snake[];
extern Size apple;


//스네이크의 머리가 사과와 닿았을 경우
void increase_score() 
{
     if (Snake_eat_apple(snake[0], apple))
     {
          score += apple.size * 10;
     }
}
