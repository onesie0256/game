#ifndef STRING_TEX_UTIL_H
#define STRING_TEX_UTIL_H
#include "../head.h"

typedef struct
{
    Uint8 fontId;
    SDL_Color color;
    Uint16 fontSize;

    SDL_Texture *texture;

    SDL_Rect *srcRect;
    SDL_Rect *dstRect;
    SDL_Rect *drawRect;
}String_Texture;

String_Texture* make_string_tex(SDL_Renderer renderer, Uint8 fontId , SDL_Color color ,Uint16 fontSize , SDL_Rect *dstRect);

void change_string_tex_color(String_Texture *stringTex , SDL_Color color);

void free_string_tex(String_Texture *stringTex);

#endif