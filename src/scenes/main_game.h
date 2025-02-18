#ifndef MAIN_GAME_H
#define MAIN_GAME_H
#include "../head.h"


int main_game(void);

int load_main_game(void);

typedef enum directions{
    East,
    NorthEast,
    North,
    NorthWest,
    West,
    SouthWest,
    South,
    SouthEast
}Directions;

void free_main_game(void);

#endif