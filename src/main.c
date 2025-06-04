#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include "ui.h"

#define FRAME_DELAY 100

void process_input() {
    int ch = getch();
    switch (ch) {
        case 'w': set_direction(UP); break;
        case 's': set_direction(DOWN); break;
        case 'a': set_direction(LEFT); break;
        case 'd': set_direction(RIGHT); break;
        case 'p':
        case 'P':
            if (game_state == GAME_PLAYING) game_state = GAME_PAUSED;
            else if (game_state == GAME_PAUSED) game_state = GAME_PLAYING;
            break;
        case 'q':
        case 'Q':
            game_state = GAME_OVER;
            break;
        case ' ':
            if (game_state == GAME_MENU || game_state == GAME_OVER) {
                init_snake();
                game_state = GAME_PLAYING;
            }
            break;
    }
}

int main() {
    initscr();             
    cbreak();               
    noecho();               
    keypad(stdscr, TRUE);   
    nodelay(stdscr, TRUE); 
    curs_set(0);            

    ui_init();              

    while (1) {
        process_input();

        if (game_state == GAME_PLAYING && !gameover) {
            move_snake();
        }

        if (gameover) {
            game_state = GAME_OVER;
        }

        ui_refresh();
        usleep(FRAME_DELAY * 1000);
    }

    endwin();  
    return 0;
}
