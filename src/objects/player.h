#ifndef PLAYER_H
#define PLAYER_H
#include "../head.h"

typedef struct player_{
    
    //大きさ、座標
    SDL_Rect *rect;

    //向き
    int dire;
    
    SDL_Texture *playerTexture; //テクスチャ
    SDL_Rect *textureRect;

    SDL_Texture *playerTextureIdle;//テクスチャ(アイドル時)
    SDL_Rect idleRect;
    int idleFlameNum;

    SDL_Texture *playerTextureRunning;//テクスチャ(移動中)
    SDL_Rect runningRect;
    int runningFlameNum;
    

    SDL_Texture *playerTexureInterect;//テクスチャ()
    SDL_Rect interectRect;
    int InterectFlameNum;


}Player;

Player* load_player(void);

void player_move(int dire);

void free_player(void);

extern Player *player;
#endif