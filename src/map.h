#ifndef MAP_H
#define MAP_H
#include "head.h"
#define MAP_WIHTH 1000
#define MAP_HEIGHT 1000


extern Uint8 mapData[MAP_HEIGHT][MAP_WIHTH];

void load_map(void);

void draw_map(void);


extern Uint16 noMoveX;
extern Uint16 noMoveY;

extern Uint8 marginX;
extern Uint8 marginY;

extern Uint16 startX;
extern Uint16 startY;
#endif