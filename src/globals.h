#ifndef GLOBALS_H
#define GLOBALS_H
#include "head.h"


//extern SDL_Surface *window; //メインウィンドウ
//extern SDL_Surface *buffer; //バッファ

extern SDL_Renderer *renderer; //メインレンダラー

extern SDL_mutex *mutex;

extern SDL_Window *window;

extern SDL_Event event; //イベント

extern int player_speed; //スピード

extern uint16_t flameDlay;


#endif