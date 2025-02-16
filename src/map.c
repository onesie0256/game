#include "map.h"

void load_map(void){
    
    load_tile();

    for (int i = 0 ; i < MAP_HEIGHT ; i++){
        for (int j = 0 ; j < MAP_WIHTH ; j++){
            mapData[i][j] = 1;
        }
    }
}

void draw_map(SDL_Surface *surface)
{
    SDL_Rect tileRect = {0 , 0 , TILE_SIZE , TILE_SIZE};
    for (int i = 0 ; i < 25 ; i++){
        for (int j = 0 ; j < 30 ; j++){
            Uint8 tileId = mapData[i][j];
            SDL_Rect dst_rect = {.x = (j * TILE_SIZE), .y = (i * TILE_SIZE), .w = TILE_SIZE, .h = TILE_SIZE};
            SDL_BlitSurface(tiles[tileId]->tileTexture , &tileRect , surface , &dst_rect);
        }
    }
}