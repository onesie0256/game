#ifndef SPRITE_H
#define SPRITE_H

#include "head.h"
#define GROUP_MAX 6
#define MAP_WIHTH 1000
#define MAP_HEIGHT 1000


typedef enum struct_types{
    MAP=6,
    PLAYER=3,
    UI=5
}Struct_type;


typedef struct sprite_node{

    Struct_type structType;//表示するやつの型
    Uint32 spriteId;//id

    SDL_Rect *srcRect;
    SDL_Rect *rect;
    SDL_Rect *drawRect;

    SDL_Surface *tetureSurface;//画像へのポインタ

    struct sprite_node *next;//次のポインタ

}Sprite_node;


void update(SDL_Surface *surface);

/*
//void add_map(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);//転送前、転送後

//void add_middle(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);

//void add_ui(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);
*/
void add_group(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface);//転送前、転送後

void load_map(void);

void sprite_init(void);

void map_draw(void);

void get_drawRect(SDL_Rect *rect , SDL_Rect *drawRect, Uint16 drawMarginX , Uint16 drawMarginY);

void get_player_drawRect(SDL_Rect *rect , SDL_Rect *drawRect);
#endif