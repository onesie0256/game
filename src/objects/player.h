#ifndef PLAYER_H
#define PLAYER_H
#include "../head.h"

typedef struct player_{
    
    //大きさ、座標
    SDL_Rect *rect;

    //向き
    //Directions direction;
    
    SDL_Surface *playerTexture; //テクスチャ
    SDL_Rect *textureRect;

    SDL_Surface *playerTextureIdle;//テクスチャ(アイドル時)
    SDL_Rect idleRect;
    int idleFlameNum;

    SDL_Surface *playerTextureRunning;//テクスチャ(移動中)
    SDL_Rect runningRect;
    int runningFlameNum;
    

    SDL_Surface *playerTexureInterect;//テクスチャ()
    SDL_Rect interectRect;
    int InterectFlameNum;


}Player;

Player* load_player(void);

extern Player *player;
#endif