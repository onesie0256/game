#ifndef MAP_H
#define MAP_H
#include "head.h"
#define MAP_WIHTH 1000
#define MAP_HEIGHT 1000


extern Uint8 mapData[MAP_HEIGHT][MAP_WIHTH];

void load_map(void);

void draw_map(SDL_Surface *surface);

#endif