#include "sprite.h"

Sprite_node *mapRoot, *middleRoot, *uiRoot;


void update(SDL_Surface *surface)
{
    SDL_FillRect(surface , NULL , SDL_MapRGBA(surface -> format , 240 , 255 , 255 , 255));//一番奥の背景を塗りつぶし 0xf0ffff

    Sprite_node *p;

    p = mapRoot;
    while (p != NULL)
    {
        SDL_BlitSurface(p->tetureSurface , p->srcRect , surface , p->dstRect);
        p = p->next;
    }

    p = middleRoot;
    while (p != NULL)
    {
        SDL_BlitSurface(p->tetureSurface , p->srcRect , surface , p->dstRect);
        p = p->next;
    }

    p = uiRoot;
    while (p != NULL)
    {
        SDL_BlitSurface(p->tetureSurface , p->srcRect , surface , p->dstRect);
        p = p->next;
    }
}

void add_map(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
    q->srcRect = srcRect;
    q->dstRect = destRect;
    q->tetureSurface = textureSurface;
    q->next = NULL;

    p = mapRoot;
    while (p != NULL)
    {
        r = p;
        p = p->next;
    }

    if(mapRoot == NULL){
        mapRoot = q;
    }
    else{
        r->next = q;
    }
    
}

void add_middle(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
    q->srcRect = srcRect;
    q->dstRect = destRect;
    q->tetureSurface = textureSurface;
    q->next = NULL;

    p = middleRoot;
    while (p != NULL)
    {
        r = p;
        p = p->next;
    }

    if(middleRoot == NULL){
        middleRoot = q;
    }
    else{
        r->next = q;
    }
    
}


void add_ui(Struct_type structType , Uint32 id ,SDL_Rect *srcRect , SDL_Rect *destRect , SDL_Surface *textureSurface)
{
    Sprite_node *p , *q , *r;

    q = (Sprite_node *)malloc(sizeof(Sprite_node));

    q->structType = structType;
    q->spriteId = id;
    q->srcRect = srcRect;
    q->dstRect = destRect;
    q->tetureSurface = textureSurface;
    q->next = NULL;

    p = uiRoot;
    while (p != NULL)
    {
        r = p;
        p = p->next;
    }

    if(uiRoot == NULL){
        uiRoot = q;
    }
    else{
        r->next = q;
    }
    
}

void sprite_init(void)
{
    mapRoot = NULL;
    middleRoot = NULL;
    uiRoot = NULL;
}