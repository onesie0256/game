#include "player.h"

Player* load_player(void)
{
    Player *p;
    p = (Player *)malloc(sizeof(Player));

    p->rect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    p->rect->x = 500;//大きさ:64x64 初期座標:(0,0)
    p->rect->y = 500;
    p->rect->w = 64;
    p->rect->h = 64;
    
    p->idleRect.x = 0;
    p->idleRect.y = 0;
    p->idleRect.w = 64;
    p->idleRect.h = 64;

    

    p->textureRect = &(p->idleRect);
    //player -> direction = East;

    p->playerTextureIdle = SDL_LoadBMP("tile_texture.bmp");
    if (p->playerTextureIdle == NULL) {
        printf("%s\n" , IMG_GetError());
        //exit(-1);
        SDL_Delay(100);
        return NULL;
    }
    p->playerTexture = p->playerTextureIdle;
    p->idleFlameNum = 1;

    return p;
}