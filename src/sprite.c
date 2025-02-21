#include "sprite.h"

Sprite_node *group[GROUP_MAX];



void update(void)
{

    //SDL_FillRect(surface , NULL , SDL_MapRGBA(surface -> format , 240 , 255 , 255 , 255));//一番奥の背景を塗りつぶし 0xf0ffff

    SDL_LockMutex(mutex);

    SDL_SetRenderDrawColor(renderer, 240, 255, 255, 255);
    SDL_RenderClear(renderer);

    Sprite_node *p;

    draw_map();

    //int drawMarginX = -startX * TILE_SIZE - marginX;
    //int drawMarginY = -startY * TILE_SIZE - marginY;

    for (int i = 0 ; i <= 3 ; i++){
        p = group[i];
        while (p != NULL)
        {
            /*
            if (p->structType == PLAYER){
                get_player_drawRect(p->rect , p->drawRect , drawMarginX , drawMarginY);
            }
            else {
                get_drawRect(p->rect , p->drawRect , drawMarginX , drawMarginY);
            }
            */
            if (p->isDisplay == SDL_TRUE){
                get_player_drawRect(p->rect , p->drawRect);
                SDL_RenderCopy(renderer , p->tetureSurface , p->srcRect , p->drawRect);
            }
            p = p->next;
        }
    }
    for (int i = 4 ; i < GROUP_MAX ; i++){
        p = group[i];
        while (p != NULL)
        {
            /*
            if (p->structType == PLAYER){
                get_player_drawRect(p->rect , p->drawRect , drawMarginX , drawMarginY);
            }
            else {
                get_drawRect(p->rect , p->drawRect , drawMarginX , drawMarginY);
            }
            */
            if (p->isDisplay == SDL_TRUE){
                SDL_RenderCopy(renderer , p->tetureSurface , p->srcRect , p->rect);
            }
            p = p->next;
        }
    }
    SDL_UnlockMutex(mutex);
}

Sprite_node* add_group(Struct_type structType , Uint32 id , SDL_bool isDisplay , SDL_Rect *srcRect , SDL_Rect *rect , SDL_Texture *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
    q->isDisplay = isDisplay;
    q->srcRect = srcRect;
    q->rect = rect;
    q->drawRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    if (q->drawRect != NULL) {
        q->drawRect->x = 0;
        q->drawRect->y = 0;
        q->drawRect->w = q->rect->w;
        q->drawRect->h = q->rect->h;
    }

    q->tetureSurface = textureSurface;
    q->next = NULL;

    p = group[structType];
    while (p != NULL)
    {
        r = p;
        p = p->next;
    }

    if(group[structType] == NULL){
        group[structType] = q;
    }
    else{
        r->next = q;
    }
    
    return q;
}




void sprite_init(void)
{
    for (int i = 0 ; i < GROUP_MAX ; i++){
        group[i] = NULL;
    }
}

void get_drawRect(SDL_Rect *rect , SDL_Rect *drawRect , Uint16 drawMarginX , Uint16 drawMarginY)
{
    drawRect->x = rect->x + drawMarginX;
    drawRect->y = rect->y + drawMarginY;
}

void get_player_drawRect(SDL_Rect *rect , SDL_Rect *drawRect)
{
    drawRect->x = player->rect->x < noMoveX ? player->rect->x : (noMoveX);
    drawRect->y = player->rect->y < noMoveY ? player->rect->y : (noMoveY);
}

void free_group(void)
{
    Sprite_node *p , *q;

    for (int i = 0 ; i < GROUP_MAX ; i++){
        p = group[i];
        while (p != NULL){
            q = p;
            free(p->drawRect);
            free(p->rect);
            //free(p->srcRect);
            SDL_DestroyTexture(p->tetureSurface);
            p = p->next;
            free(q);
        }
    }
}