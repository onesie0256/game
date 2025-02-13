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

    p->playerTextureIdle = SDL_LoadBMP("assets/img/player_test.bmp");
    if (p->playerTextureIdle == NULL) {
        printf("%s\n" , IMG_GetError());
        exit(-1);
        SDL_Delay(100);
        return NULL;
    }
    SDL_SetColorKey(p->playerTextureIdle , SDL_SRCCOLORKEY , -1);

    p->playerTexture = p->playerTextureIdle;
    p->idleFlameNum = 1;

    return p;
}

void player_move(int dire)
{
    switch (dire)
    {
    case East:
        player->rect->x += player_speed;
        break;
    
    case West:
        player->rect->x -= player_speed;
        break;

    case North:
        player->rect->y -= player_speed;
        break;

    case South:
        player->rect->y += player_speed;
        break;

    case NorthEast:
        player->rect->x += player_speed;
        player->rect->y -= player_speed;
        break;

    case NorthWest:
        player->rect->x -= player_speed;
        player->rect->y -= player_speed;
        break;

    case SouthEast:
        player->rect->x += player_speed;
        player->rect->y += player_speed;
        break;

    case SouthWest:
        player->rect->x -= player_speed;
        player->rect->y += player_speed;
        break;

    default:
        break;
    }
}