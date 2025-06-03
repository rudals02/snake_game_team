#include "ui.h"
#include "score.h"
#include <stdio.h>
#include <ncurses.h>  // windows.h 대신 ncurses.h 사용

extern int snake_length;

// 외부 함수 선언 추가  
void draw_snake(void);
void draw_apple(void);
// 게임 상태 변수
GameState game_state = GAME_MENU;

// 화면 초기화
void ui_init(void) {
    // ncurses 초기화
    initscr();              // ncurses 시작
    noecho();               // 키 입력 시 화면에 표시 안함
    curs_set(0);            // 커서 숨기기
    keypad(stdscr, TRUE);   // 특수 키 (화살표 등) 사용 가능
    nodelay(stdscr, TRUE);  // 입력 대기하지 않음
    
    ui_clear();
}

// 화면 지우기
void ui_clear(void) {
    clear();  // ncurses의 clear 함수
}

// 특정 위치에 문자 출력
void ui_draw_at(int x, int y, char ch) {
    mvaddch(y, x, ch);  // ncurses는 y, x 순서임에 주의
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
    mvprintw(HEIGHT + 1, 0, "score: %d  |  length: %d  |  [P] Pause  |  [Q] Quit", score, snake_length);
}

// 메뉴 화면 표시
void ui_draw_menu(void) {
    ui_clear();
    mvprintw(HEIGHT/2 - 3, WIDTH/2 - 10, "=== snake game ===");
    mvprintw(HEIGHT/2, WIDTH/2 - 8, "[SPACE] game start");
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 8, "[Q] Quit game");
}

// 게임 오버 화면 표시
void ui_draw_gameover(void) {
    mvprintw(HEIGHT/2 - 2, WIDTH/2 - 5, "GAME OVER!");
    mvprintw(HEIGHT/2, WIDTH/2 - 8, "final score: %d", score);
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 10, "[SPACE] restart");
    mvprintw(HEIGHT/2 + 3, WIDTH/2 - 8, "[Q] Quit game");
}

// 일시정지 화면 표시
void ui_draw_pause(void) {
    mvprintw(HEIGHT/2, WIDTH/2 - 5, "Pause");
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 8, "[P] Progress");
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
    
    refresh();  // ncurses 화면 업데이트
}

// 프로그램 종료 시 호출 (ncurses 정리)
void ui_cleanup(void) {
    endwin();  // ncurses 종료
}
