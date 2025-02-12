#ifndef SPRITE_H
#define SPRITE_H

#include "head.h"

typedef enum struct_types{
    PLAYER
}Struct_type;


typedef struct sprite_node{

    Struct_type structType;//表示するやつの型
    Uint32 spriteId;//id

    SDL_Rect *srcRect;
    SDL_Rect *dstRect;

    SDL_Surface *tetureSurface;//画像へのポインタ

    struct sprite_node *next;//次のポインタ

}Sprite_node;


void update(SDL_Surface *surface);

void add_map(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);//転送前、転送後

void add_middle(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);

void add_ui(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);

void sprite_init(void);


#endif