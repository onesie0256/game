#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H
#include "../head.h"

#define SELECTER(ONE_, TWO_, THREE_ , FOUR_ , FIVE_  , SELECT ,  ...) SELECT
#define is_in_square(...) SELECTER(__VA_ARGS__, 5 , is_in_square4 , 3 , 2 , is_in_square1) (__VA_ARGS__)

SDL_bool is_in_square4(int xStart , int yStart , int xEnd , int yEnd);

SDL_bool is_in_square1(SDL_Rect rect);

#endif

