#include "score.h"
#include <stdio.h>

int score = 0;


//뱀이 사과와 닿으면 점수 추가하기
int Snake_eat_apple(position snakeHead, Size apple) 
{
     return (snakeHead.x >= apple.apple_pos.x - apple.apple_size && snakeHead.x <= apple.apple_pos.x + apple.apple_size &&
        snakeHead.y >= apple.apple_pos.y - apple.apple_size && snakeHead.y <= apple.apple_pos.y + apple.apple_size);
}

extern position snake[];
extern Size apple;


//스네이크의 머리가 사과와 닿았는지 확?인 하기
void increase_score() 
{
     if (Snake_eat_apple(snake[0], apple))
     {
          score += apple.apple_size * 10;
     }
}
