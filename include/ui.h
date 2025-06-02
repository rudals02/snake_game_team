#ifndef UI_H
#define UI_H

#include "physics.h"

// 게임 상태 정의
typedef enum {
    GAME_MENU,
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_OVER
} GameState;

// 현재 게임 상태
extern GameState game_state;

// 화면 초기화
void ui_init(void);

// 화면 지우기
void ui_clear(void);

// 특정 위치에 문자 출력
void ui_draw_at(int x, int y, char ch);

// 게임 화면 테두리 그리기
void ui_draw_border(void);

// 점수 및 게임 정보 표시
void ui_draw_info(void);

// 메뉴 화면 표시
void ui_draw_menu(void);

// 게임 오버 화면 표시
void ui_draw_gameover(void);

// 일시정지 화면 표시
void ui_draw_pause(void);

// 전체 게임 화면 그리기
void ui_refresh(void);

// 커서 위치 이동
void ui_gotoxy(int x, int y);

#endif
