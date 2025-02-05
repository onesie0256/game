#include "image_utils.h"

SDL_bool is_in_square4(int xStart , int yStart , int xEnd , int yEnd)
{
    return ((xStart <= event.motion.x && event.motion.x <= xEnd) && (yStart <= event.motion.y && event.motion.y <= yEnd)) ? SDL_TRUE : SDL_FALSE;
}

SDL_bool is_in_square1(SDL_Rect rect)
{
    return ((rect.x <= event.motion.x && event.motion.x <= (rect.x + rect.w)) && (rect.y <= event.motion.y && event.motion.y <= (rect.y + rect.h))) ? SDL_TRUE : SDL_FALSE;
}