#include "physics.h"


//사과 랜덤 위치, 사이즈 생성
Size RandomAppleSize(){
    Size apple;
    apple.pos.x=rand()%WIDTH;
    apple.pos.y=rand()%HEIGHT;
    apple.size=(rand()%3)+1;  //크기 1~3
    return apple;
} 

//벽 충동 검사
int CrushedToWall(position snakeHead){
    return (snakeHead.x<0 || snakeHead.x>=WIDTH || snakeHead.y<0 || snakeHead.y>=HEIGHT);
}





