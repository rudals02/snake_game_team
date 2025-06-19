#ifndef UI_H
#define UI_H

#include "physics.h"

typedef enum {
    GAME_MENU,
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_OVER
} GameState;

extern GameState game_state;

void ui_init(void);
void ui_clear(void);
void ui_draw_at(int x, int y, char ch);
void ui_draw_border(void);
void ui_draw_info(void);
void ui_draw_menu(void);
void ui_draw_gameover(void);
void ui_draw_pause(void);
void ui_refresh(void);
void ui_cleanup(void);

#endif
