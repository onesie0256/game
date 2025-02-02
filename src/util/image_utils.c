#include "image_utils.h"

SDL_bool is_in_square(int xStart , int yStart , int xEnd , int yEnd)
{
    return ((xStart <= event.motion.x && event.motion.x <= xEnd) && (yStart <= event.motion.y && event.motion.y <= yEnd)) ? SDL_TRUE : SDL_FALSE;
}