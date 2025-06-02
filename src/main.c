#include <conio.h>  // position, Size, direction, WIDTH, HEIGHT 등을 제각각 선언하게 되면 타입 충돌이나 중복 정의가 생길 수 있기에 사용용
#include <windows.h>
#include "snake.h"
#include "ui.h"

// 입력 간 딜레이(ms)
#define FRAME_DELAY 100

// 키 입력 처리 함수
void process_input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
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
}

// 메인 함수
int main() {
    ui_init();  // 콘솔 초기화

    while (1) {
        process_input();

        if (game_state == GAME_PLAYING && !gameover) {
            move_snake();
        }

        if (gameover) {
            game_state = GAME_OVER;
        }

        ui_refresh();
        Sleep(FRAME_DELAY);
    }

    return 0;
}


