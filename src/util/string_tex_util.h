#ifndef STRING_TEX_UTIL_H
#define STRING_TEX_UTIL_H
#include "../head.h"

typedef struct{ //文字を簡単にレンダリングするための構造体
    Uint8 fontId; //フォントid
    SDL_Color color; //文字カラー
    Uint16 fontSize; //フォントサイズ
    char *text; //描く文字

    SDL_Texture *texture; //文字が描かれたテクスチャ
    SDL_Texture *destTexture; //転送先テクスチャ

    SDL_Rect *srcRect; //文字テクスチャ自身の領域
    SDL_Rect *dstRect; //
    SDL_Rect *drawRect;
}String_Texture;

String_Texture* make_string_tex(Uint8 fontId , SDL_Color color ,Uint16 fontSize , char *text , SDL_Texture *destTexture , SDL_Rect *dstRect);

void change_string_tex_color(String_Texture *stringTex , SDL_Color color);

void free_string_tex(String_Texture *stringTex);

#endif