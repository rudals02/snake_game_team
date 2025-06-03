#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include "ui.h"

#define FRAME_DELAY 100

// 입력 처리
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

// 메인 함수
int main() {
    initscr();              // ncurses 초기화
    cbreak();               // 줄 버퍼링 끄기
    noecho();               // 입력 키 출력 안함
    keypad(stdscr, TRUE);   // 방향키 허용
    nodelay(stdscr, TRUE);  // getch() 논블로킹
    curs_set(0);            // 커서 숨기기

    ui_init();              // 사용자 정의 초기화 (필요 시 화면 준비)

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

    endwin();  // ncurses 종료
    return 0;
}
