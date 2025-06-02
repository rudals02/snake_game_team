#include "ui.h"
#include "score.h"
#include <stdio.h>
#include <windows.h>

// 게임 상태 변수
GameState game_state = GAME_MENU;

// 커서 위치 이동 (Windows 콘솔)
void ui_gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 화면 초기화
void ui_init(void) {
    // 커서 숨기기
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    
    ui_clear();
}

// 화면 지우기
void ui_clear(void) {
    system("cls");
}

// 특정 위치에 문자 출력
void ui_draw_at(int x, int y, char ch) {
    ui_gotoxy(x, y);
    printf("%c", ch);
}

// 게임 화면 테두리 그리기
void ui_draw_border(void) {
    // 상단 테두리
    for (int x = 0; x < WIDTH; x++) {
        ui_draw_at(x, 0, '#');
    }
    // 하단 테두리
    for (int x = 0; x < WIDTH; x++) {
        ui_draw_at(x, HEIGHT - 1, '#');
    }
    // 좌측 테두리
    for (int y = 0; y < HEIGHT; y++) {
        ui_draw_at(0, y, '#');
    }
    // 우측 테두리
    for (int y = 0; y < HEIGHT; y++) {
        ui_draw_at(WIDTH - 1, y, '#');
    }
}

// 점수 및 게임 정보 표시
void ui_draw_info(void) {
    ui_gotoxy(0, HEIGHT + 1);
    printf("점수: %d  |  길이: %d  |  [P] 일시정지  |  [Q] 종료", score, snake_length);
}

// 메뉴 화면 표시
void ui_draw_menu(void) {
    ui_clear();
    ui_gotoxy(WIDTH/2 - 10, HEIGHT/2 - 3);
    printf("=== 스네이크 게임 ===");
    ui_gotoxy(WIDTH/2 - 8, HEIGHT/2);
    printf("[SPACE] 게임 시작");
    ui_gotoxy(WIDTH/2 - 8, HEIGHT/2 + 2);
    printf("[Q] 게임 종료");
}

// 게임 오버 화면 표시
void ui_draw_gameover(void) {
    ui_gotoxy(WIDTH/2 - 5, HEIGHT/2 - 2);
    printf("GAME OVER!");
    ui_gotoxy(WIDTH/2 - 8, HEIGHT/2);
    printf("최종 점수: %d", score);
    ui_gotoxy(WIDTH/2 - 10, HEIGHT/2 + 2);
    printf("[SPACE] 다시 시작");
    ui_gotoxy(WIDTH/2 - 8, HEIGHT/2 + 3);
    printf("[Q] 게임 종료");
}

// 일시정지 화면 표시
void ui_draw_pause(void) {
    ui_gotoxy(WIDTH/2 - 5, HEIGHT/2);
    printf("일시 정지");
    ui_gotoxy(WIDTH/2 - 8, HEIGHT/2 + 2);
    printf("[P] 계속하기");
}

// 전체 게임 화면 그리기
void ui_refresh(void) {
    switch (game_state) {
        case GAME_MENU:
            ui_draw_menu();
            break;
            
        case GAME_PLAYING:
            ui_clear();
            ui_draw_border();
            draw_snake();
            draw_apple();
            ui_draw_info();
            break;
            
        case GAME_PAUSED:
            ui_draw_pause();
            break;
            
        case GAME_OVER:
            ui_draw_gameover();
            break;
    }
    
    ui_gotoxy(0, HEIGHT + 3);  // 커서를 화면 밖으로
}
