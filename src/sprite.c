#include "sprite.h"

Sprite_node *group[GROUP_MAX];



void update(SDL_Surface *surface)
{

    SDL_FillRect(surface , NULL , SDL_MapRGBA(surface -> format , 240 , 255 , 255 , 255));//一番奥の背景を塗りつぶし 0xf0ffff

    Sprite_node *p;

    draw_map(surface);

    //int drawMarginX = -startX * TILE_SIZE - marginX;
    //int drawMarginY = -startY * TILE_SIZE - marginY;

    for (int i = 0 ; i < GROUP_MAX ; i++){
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
            get_player_drawRect(p->rect , p->drawRect);
            SDL_BlitSurface(p->tetureSurface , p->srcRect , surface , p->drawRect);
            p = p->next;
        }
    }

}

void add_group(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *rect , SDL_Surface *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
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
    
}




void sprite_init(void)
{
    for (int i = 0 ; i < GROUP_MAX ; i++){
        group[i] = NULL;
    }
}

void get_drawRect(SDL_Rect *rect , SDL_Rect *drawRect , Uint16 drawMarginX , Uint16 drawMarginY )
{
    drawRect->x = rect->x + drawMarginX;
    drawRect->y = rect->y + drawMarginY;
}

void get_player_drawRect(SDL_Rect *rect , SDL_Rect *drawRect)
{
    drawRect->x = player->rect->x < noMoveX ? player->rect->x : (noMoveX);
    drawRect->y = player->rect->y < noMoveY ? player->rect->y : (noMoveY);
}