#include "ui.h"
#include "score.h"
#include <stdio.h>
#include <ncurses.h>

extern int snake_length;

// 외부함수들
void draw_snake(void);
void draw_apple(void);

GameState game_state = GAME_MENU;

void ui_init(void) {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    
    ui_clear();
}

void ui_clear(void) {
    clear();
}

void ui_draw_at(int x, int y, char ch) {
    mvaddch(y, x, ch);
}

void ui_draw_border(void) {
    int i;
    
    // 위아래 벽 그리기
    for(i = 0; i < WIDTH; i++) {
        ui_draw_at(i, 0, '#');
        ui_draw_at(i, HEIGHT-1, '#');
    }
    
    // 양옆 벽 그리기
    for(i = 0; i < HEIGHT; i++) {
        ui_draw_at(0, i, '#');
        ui_draw_at(WIDTH-1, i, '#');
    }
}

void ui_draw_info(void) {
    mvprintw(HEIGHT + 1, 0, "Score: %d  |  Length: %d  |  [P] Pause  |  [Q] Quit", 
             score, snake_length);
}

void ui_draw_menu(void) {
    ui_clear();
    
    mvprintw(HEIGHT/2 - 3, WIDTH/2 - 10, "=== SNAKE GAME ===");
    mvprintw(HEIGHT/2, WIDTH/2 - 8, "[SPACE] Start Game");
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 8, "[Q] Quit Game");
}

void ui_draw_gameover(void) {
    mvprintw(HEIGHT/2 - 2, WIDTH/2 - 5, "GAME OVER!");
    mvprintw(HEIGHT/2, WIDTH/2 - 8, "Final Score: %d", score);
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 10, "[SPACE] Play Again");
    mvprintw(HEIGHT/2 + 3, WIDTH/2 - 8, "[Q] Quit Game");
}

void ui_draw_pause(void) {
    mvprintw(HEIGHT/2, WIDTH/2 - 5, "PAUSED");
    mvprintw(HEIGHT/2 + 2, WIDTH/2 - 8, "[P] Resume Game");
}

void ui_refresh(void) {
    if(game_state == GAME_MENU) {
        ui_draw_menu();
    }
    else if(game_state == GAME_PLAYING) {
        ui_clear();
        ui_draw_border();
        draw_snake();
        draw_apple();
        ui_draw_info();
    }
    else if(game_state == GAME_PAUSED) {
        ui_draw_pause();
    }
    else if(game_state == GAME_OVER) {
        ui_draw_gameover();
    }
    
    refresh();
}

void ui_cleanup(void) {
    endwin();
}
