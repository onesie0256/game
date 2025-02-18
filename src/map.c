#include "map.h"

void load_map(void){
    
    load_tile();

    for (int i = 0 ; i < MAP_HEIGHT ; i++){
        for (int j = 0 ; j < MAP_WIHTH ; j++){
            mapData[i][j] = 1;
        }
    }

    mapData[0][0] = collision_tile;
}

void draw_map(void)
{
    //SDL_Surface *mapBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE , SCREEN_WIDTH , SCREEN_HEIGHT , 32 , 0xff000000 , 0x00ff0000 , 0x0000ff00 , 0x000000ff);

    SDL_Rect tileRect = {0 , 0 , TILE_SIZE , TILE_SIZE};

    noMoveX = 15 * TILE_SIZE; //一画面に映るタイルの数は横30、縦17
    noMoveY = 8 * TILE_SIZE;

    /*marginX = player->rect->x % TITLE_SIZE;
    marginY = player->rect->y % TITLE_SIZE;
    
    startX = (player->rect->x <= noMoveX) ? 0 : (player->rect->x / TILE_SIZE - noMoveX / TILE_SIZE);
    startY = (player->rect->y <= noMoveY) ? 0 : (player->rect->y / TILE_SIZE - noMoveY / TILE_SIZE);
    */

    marginX = 0;
    marginY = 0;

    if (player->rect->x <= noMoveX){
        startX = 0;
    }
    else {
        startX = (player->rect->x / TILE_SIZE - noMoveX / TILE_SIZE);
        marginX = player->rect->x % TITLE_SIZE;
    }

    if (player->rect->y <= noMoveY){
        startY = 0;
    }
    else {
        startY = (player->rect->y / TILE_SIZE - noMoveY / TILE_SIZE);
        marginY = player->rect->y % TITLE_SIZE;
    }

    for (int i = startY ; i < startY + 25 ; i++){
        for (int j = startX ; j < startX + 40 ; j++){
            Uint8 tileId = mapData[i][j];
            SDL_Rect dst_rect = {.x = (j - startX) * TILE_SIZE - marginX , .y = (i - startY) * TILE_SIZE - marginY , .w = TILE_SIZE, .h = TILE_SIZE};
            //SDL_BlitSurface(tiles[tileId]->tileTexture , &tileRect , surface , &dst_rect);
            SDL_RenderCopy(renderer , tiles[tileId]->tileTexture , &tileRect , &dst_rect);
        }
    }


}