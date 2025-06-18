#ifndef PHYSICS_H   //파일 중복 포함 방지
#define PHYSICS_H

#include <stdlib.h>

#define WIDTH 80    //게임 화면 가로, 세로 크기 정의
#define HEIGHT 24

//좌표(x, y)
typedef struct
{
    int x;
    int y; //x: 가로 위치, y: 세로 위치
} position;


//사과의 위치와 크기
typedef struct
{
    position apple_pos; //사과 위치->apple_pos.x, apple_pos.y
    int apple_size;  //사과 크기(뱀이 먹으면 얼마나 길어지는지)
} Size;

//사과 랜덤 위치와 크기(1~3)생성
Size RandomApple();

//뱀 머리가 벽에 부딪혔는지 확인, 반환값: 1->충돌, 0->정상
int CrushedToWall(position snakeHead);



#endif
