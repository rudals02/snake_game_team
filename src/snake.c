#include "snake.h"
#include "physics.h"
#include "score.h"
#include "ui.h"
#include <stdlib.h>
#include <time.h>

// 최대 뱀 길이
#define MAX_SNAKE_LENGTH 100

// 외부 참조 변수
position snake[MAX_SNAKE_LENGTH];  // 뱀의 몸통 좌표 배열
int snake_length = 3;              // 초기 뱀 길이
int gameover = 0;                  // 게임 오버 여부
Size apple;                        // 현재 사과

// 현재 방향 저장
direction current_direction = RIGHT;

// 방향 설정 함수
void set_direction(direction dir) {
    // 반대 방향으로는 이동 금지
    if ((current_direction == UP && dir == DOWN) ||
        (current_direction == DOWN && dir == UP) ||
        (current_direction == LEFT && dir == RIGHT) ||
        (current_direction == RIGHT && dir == LEFT)) {
        return;
    }
    current_direction = dir;
}

// 뱀 초기화
void init_snake(void) {
    snake_length = 3;
    current_direction = RIGHT;

    // 초기 위치 설정 (중앙 근처)
    int start_x = WIDTH / 2;
    int start_y = HEIGHT / 2;
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = start_x - i;
        snake[i].y = start_y;
    }

    // 랜덤 시드 초기화
    srand(time(NULL));

    // 첫 사과 생성
    apple = RandomApple();
}

// 뱀 이동
void move_snake(void) {
    // 이전 위치 저장 (꼬리까지)
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // 머리 이동
    switch (current_direction) {
        case UP:    snake[0].y--; break;
        case DOWN:  snake[0].y++; break;
        case LEFT:  snake[0].x--; break;
        case RIGHT: snake[0].x++; break;
    }

    // 벽 충돌 검사
    if (CrushedToWall(snake[0])) {
        gameover = 1;
        return;
    }

    // 사과 먹었는지 확인 및 점수 증가
    if (Snake_eat_apple(snake[0], apple)) {
        increase_score();
        grow_snake(apple.apple_size);
        apple = RandomApple();  // 새로운 사과 생성
    }

    // 자기 몸과 충돌 확인
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameover = 1;
            return;
        }
    }
}

// 뱀 성장
void grow_snake(int size) {
    // 최대 길이 초과 방지
    if (snake_length + size >= MAX_SNAKE_LENGTH) {
        size = MAX_SNAKE_LENGTH - snake_length;
    }

    // 새로운 꼬리 추가
    for (int i = 0; i < size; i++) {
        snake[snake_length] = snake[snake_length - 1];  // 마지막 위치 복사
        snake_length++;
    }
}

// 뱀 그리기
void draw_snake(void) {
    for (int i = 0; i < snake_length; i++) {
        char body = (i == 0) ? 'O' : 'o';  // 머리는 O, 몸통은 o
        ui_draw_at(snake[i].x, snake[i].y, body);
    }
}

// 사과 그리기
void draw_apple(void) {
    for (int dx = -apple.apple_size; dx <= apple.apple_size; dx++) {
        for (int dy = -apple.apple_size; dy <= apple.apple_size; dy++) {
            int ax = apple.apple_pos.x + dx;
            int ay = apple.apple_pos.y + dy;

            // 범위 내에서만 출력
            if (ax >= 0 && ax < WIDTH && ay >= 0 && ay < HEIGHT) {
                ui_draw_at(ax, ay, '@');
            }
        }
    }
}
