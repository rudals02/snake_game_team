#ifndef UI_H
#define UI_H

#include <stdint.h>

// 화면 크기
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

// 게임 상태
typedef enum {
    GAME_MENU,
    GAME_PLAYING,
    GAME_OVER
} GameState;

// UI 초기화
void ui_init(void);

// 화면 지우기
void ui_clear(void);

// 게임 화면 그리기
void ui_draw_game_border(void);

// 메인 메뉴 그리기
void ui_draw_menu(void);

// 게임 오버 화면 그리기
void ui_draw_game_over(int score);

// 점수 표시 업데이트
void ui_update_score(int score);

// 특정 위치에 문자 출력
void ui_draw_at(int x, int y, char c);

// 특정 위치에 문자열 출력
void ui_print_at(int x, int y, const char* str);

// 커서 위치 이동
void ui_move_cursor(int x, int y);

#endif // UI_H
