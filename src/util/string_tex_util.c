#include "string_tex_util.h"

TTF_Font *make_font(Uint8 fontId ,Uint16 fontSize);

String_Texture* make_string_tex(Uint8 fontId , SDL_Color color ,Uint16 fontSize , char *text , SDL_Texture *destTexture , SDL_Rect *dstRect)
{
    String_Texture *p = (String_Texture *)malloc(sizeof(String_Texture));

    p->srcRect  = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->dstRect  = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->drawRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->text = (char *)malloc(sizeof(char) * strlen(text) + 1);

    p->color = color;
    p->fontId = fontId;
    p->fontSize = fontSize;
    p->destTexture = destTexture;
    strcpy(p->text , text);

    TTF_Font *font = make_font(p->fontId , p->fontSize);
    SDL_Surface *stringSurface = TTF_RenderUTF8_Blended(font , text , p->color);

    p->texture = SDL_CreateTextureFromSurface(renderer , stringSurface);

    p->srcRect->x = 0;
    p->srcRect->y = 0;
    p->srcRect->w = stringSurface->w;
    p->srcRect->h = stringSurface->h;

    p->dstRect->x = dstRect->x;
    p->dstRect->y = dstRect->y;
    p->dstRect->w = stringSurface->w;
    p->dstRect->h = stringSurface->h;

    SDL_FreeSurface(stringSurface);
    TTF_CloseFont(font);

    return p;

}

void change_string_tex_color(String_Texture *stringTex , SDL_Color color)
{
    stringTex->color = color;

    TTF_Font *font = make_font(stringTex->fontId , stringTex->fontSize);
    SDL_Surface *stringSurface = TTF_RenderText_Blended(font , stringTex->text , stringTex->color);

    SDL_DestroyTexture(stringTex->texture);
    stringTex->texture = SDL_CreateTextureFromSurface(renderer , stringSurface);

    TTF_CloseFont(font);
}

void free_string_tex(String_Texture *stringTex)
{
    SDL_DestroyTexture(stringTex->texture);
    free(stringTex->srcRect);
    free(stringTex->dstRect);
    free(stringTex->drawRect);
    free(stringTex);
}

TTF_Font *make_font(Uint8 fontId , Uint16 fontSize)
{
    char fontPath[40] = "assets/fonts/";

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