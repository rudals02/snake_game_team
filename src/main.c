#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include "ui.h"

#define FRAME_DELAY 100

void process_input() {
    int ch = getch(); 

    if (ch == 'w' || ch == 'W' || ch == KEY_UP) {
        set_direction(UP);
    } 

    else if (ch == 's' || ch == 'S' || ch == KEY_DOWN) {
        set_direction(DOWN);
    } 

    else if (ch == 'a' || ch == 'A' || ch == KEY_LEFT) {
        set_direction(LEFT);
    } 

    else if (ch == 'd' || ch== 'D' || ch == KEY_RIGHT) {
        set_direction(RIGHT);
    } 

    else if (ch == 'p' || ch == 'P') {
        if (game_state == GAME_PLAYING) {
            game_state = GAME_PAUSED;
        }

        else if (game_state == GAME_PAUSED) {
            game_state = GAME_PLAYING;
        }
    } 

    else if (ch == 'q' || ch == 'Q') {
        game_state = GAME_OVER;
    } 
    
    else if (ch == ' ') {
        if (game_state == GAME_MENU || game_state == GAME_OVER) {
            init_snake();
            game_state = GAME_PLAYING;
        }
    }
}


int main() {

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
