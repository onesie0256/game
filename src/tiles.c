#include "tiles.h"

void load_tile(void){

    SDL_Rect tileRect = {0 , 0 , TILE_SIZE , TILE_SIZE};

    Tile *p0 = (Tile *)malloc(sizeof(Tile));

    p0->id = unknownTile;
    p0->isCollision = SDL_FALSE;
    p0->tileTexture = SDL_LoadBMP("assets/img/unknownTile.bmp");

    tiles[0] = p0;

    Tile *p1 = (Tile *)malloc(sizeof(Tile));

    p1->id = emptyTile;
    p1->isCollision = SDL_FALSE;
    p1->tileTexture = SDL_LoadBMP("assets/img/tile_texture.bmp");

    tiles[1] = p1;


}