#ifndef SNAKE_H   // 파일 중복 포함 방지
#define SNAKE_H

#include "physics.h"  // 위치,크기 구조체 사용을 위해 포함

// 뱀 이동 방향 정의
typedef enum { UP, DOWN, LEFT, RIGHT } direction;

// 뱀 몸 좌표 배열 (snake[0]이 머리)
extern position snake[];

// 현재 뱀 길이
extern int snake_length;

// 게임 오버 여부 (1: 종료, 0: 진행 중)
extern int gameover;

// 현재 사과 정보 (위치, 크기)
extern Size apple;

// 뱀 초기화 (길이, 방향, 위치 설정)
void init_snake(void);

// 뱀 이동 (방향에 따라 한 칸 이동)
void move_snake(void);

// 뱀 성장 (사과 크기만큼 꼬리 늘리기)
void grow_snake(int size);

// 뱀 출력 (머리: O, 몸통: o)
void draw_snake(void);

// 사과 출력 (크기에 따라 범위 표시)
void draw_apple(void);

// 이동 방향 설정 (반대 방향 이동 방지 포함)
void set_direction(direction dir);

#endif
