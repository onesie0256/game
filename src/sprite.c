#include "sprite.h"

Sprite_node *group[GROUP_MAX];



void update(SDL_Surface *surface)
{
    SDL_FillRect(surface , NULL , SDL_MapRGBA(surface -> format , 240 , 255 , 255 , 255));//一番奥の背景を塗りつぶし 0xf0ffff

    Sprite_node *p;

    draw_map(surface);

    for (int i = 0 ; i < GROUP_MAX ; i++){
        p = group[i];
        while (p != NULL)
        {
            SDL_BlitSurface(p->tetureSurface , p->srcRect , surface , p->dstRect);
            p = p->next;
        }
    }

}

void add_group(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
    q->srcRect = srcRect;
    q->dstRect = destRect;
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