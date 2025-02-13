/**
 * グローバル変数を定義
 */
#include "globals.h"


SDL_Surface *window; 
SDL_Surface *buffer;

SDL_Event event;

int player_speed = 8;

uint16_t flameDlay = 1000 / FPS;

Player *player;
