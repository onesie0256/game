/**
 * グローバル変数を定義
 */
#include "globals.h"


SDL_Surface *window; 
SDL_Surface *buffer;

SDL_Event event;

int player_speed = 8;

uint16_t flameDlay = 1000 / FPS;

Player *player; //プレイヤーの構造体

Tile *tils[TILE_KIND]; //タイルの情報を格納
SDL_Rect tileRect = {0 , 0 , TILE_SIZE , TILE_SIZE};
Tile *tiles[TILE_KIND];

Uint8 mapData[MAP_HEIGHT][MAP_WIHTH]; //マップの情報を格納

Uint16 noMoveX;
Uint16 noMoveY;