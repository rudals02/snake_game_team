#include "physics.h"
#include <stdlib.h>

//사과 랜덤 위치, 사이즈 생성
Size RandomApple(){
    Size apple; //apple.apple_pos.x, apple.apple_pos.y, apple.apple_size
    apple.apple_pos.x=rand()%WIDTH; //사과 x위치: 0~79
    apple.apple_pos.y=rand()%HEIGHT; //사과 y위치: 0~23
    apple.apple_size=(rand()%3)+1;  //사과 크기: rand()%3->0~2  +1->1~3
    return apple;
} 

extern Size RandomApple_asm();

//벽 충동 검사
int CrushedToWall(position snakeHead){
    if (snakeHead.x<0 || snakeHead.x>=WIDTH ||snakeHead.y<0 || snakeHead.y>=HEIGHT){
        return 1;
    }
    return 0;
}







