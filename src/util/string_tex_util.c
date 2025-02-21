#include "string_tex_util.h"

TTF_Font *make_font(Uint8 fontId ,Uint16 fontSize);

String_Texture* make_string_tex(Uint8 fontId , SDL_Color color ,Uint16 fontSize , char *text , SDL_Renderer *renderer , SDL_Rect *dstRect)
{
    String_Texture *p = (String_Texture *)malloc(sizeof(String_Texture));

    p->srcRect  = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->dstRect  = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->drawRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));

    p->color = color;
    p->fontId = fontId;
    p->fontSize = fontId;

    TTF_Font *font = make_font(p->fontId , p->fontSize);
    SDL_Surface *stringSurface = TTF_RenderText_Blended(font , text , p->color);

    p->texture = SDL_CreateTextureFromSurface(renderer , stringSurface);




}

void change_string_tex_color(SDL_Color color);

void free_string_tex(String_Texture *stringTex);

TTF_Font *make_font(Uint8 fontId , Uint16 fontSize)
{
    char *fontPath = "assets/fonts/";

    char *fontFileName;

    switch (fontId)
    {
    case 1:
        fontFileName = "azuki.ttf";
        break;
    
    default:
        break;
    }

    strcat(fontPath , fontFileName);

    TTF_Font *font = TTF_OpenFont(fontPath , fontSize);

    return font;
} 