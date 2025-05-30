 #include "../include/ui.h"
#include <stdio.h>
#include <stdlib.h>

// UI 초기화
void ui_init(void) {
    // 화면 지우고 커서 숨기기
    printf("\033[?25l");  // 커서 숨기기
    ui_clear();
}

// 화면 지우기
void ui_clear(void) {
    printf("\033[2J\033[H");  // 화면 지우고 커서를 (0,0)으로
    fflush(stdout);
}

// 커서 위치 이동
void ui_move_cursor(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

// 특정 위치에 문자 출력
void ui_draw_at(int x, int y, char c) {
    ui_move_cursor(x, y);
    printf("%c", c);
    fflush(stdout);
}

// 특정 위치에 문자열 출력
void ui_print_at(int x, int y, const char* str) {
    ui_move_cursor(x, y);
    printf("%s", str);
    fflush(stdout);
}

// 게임 화면 테두리 그리기
void ui_draw_game_border(void) {
    // 상단 테두리
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        ui_draw_at(x, 0, '#');
    }
    
    // 하단 테두리
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        ui_draw_at(x, SCREEN_HEIGHT - 1, '#');
    }
    
    // 좌측 테두리
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        ui_draw_at(0, y, '#');
    }
    
    // 우측 테두리
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        ui_draw_at(SCREEN_WIDTH - 1, y, '#');
    }
    
    // 점수 표시 영역
    ui_print_at(SCREEN_WIDTH + 2, 2, "SCORE: 0");
    
    // 조작 안내
    ui_print_at(SCREEN_WIDTH + 2, 5, "Controls:");
    ui_print_at(SCREEN_WIDTH + 2, 6, "W - Up");
    ui_print_at(SCREEN_WIDTH + 2, 7, "A - Left");
    ui_print_at(SCREEN_WIDTH + 2, 8, "S - Down");
    ui_print_at(SCREEN_WIDTH + 2, 9, "D - Right");
    ui_print_at(SCREEN_WIDTH + 2, 11, "Q - Quit");
}

// 메인 메뉴 그리기
void ui_draw_menu(void) {
    ui_clear();
    
    ui_print_at(15, 5, "=== SNAKE GAME ===");
    ui_print_at(12, 8, "Press ENTER to start");
    ui_print_at(15, 10, "Press Q to quit");
    
    ui_print_at(10, 13, "Game Rules:");
    ui_print_at(10, 14, "- Use WASD to move");
    ui_print_at(10, 15, "- Eat apples to grow");
    ui_print_at(10, 16, "- Don't hit walls or yourself!");
}

// 게임 오버 화면 그리기
void ui_draw_game_over(int score) {
    ui_clear();
    
    ui_print_at(15, 8, "=== GAME OVER ===");
    
    char score_text[50];
    sprintf(score_text, "Your Score: %d", score);
    ui_print_at(14, 10, score_text);
    
    ui_print_at(11, 13, "Press R to restart");
    ui_print_at(13, 14, "Press Q to quit");
}

// 점수 업데이트
void ui_update_score(int score) {
    char score_text[20];
    sprintf(score_text, "SCORE: %d", score);
    ui_print_at(SCREEN_WIDTH + 2, 2, score_text);
}

