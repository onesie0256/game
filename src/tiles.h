#ifndef TILES_H
#define TILES_H
#include "head.h"
#define TILE_KIND 2
#define TILE_SIZE 64

typedef enum tile_name{
    unknownTile,
    emptyTile
}Tile_name;

typedef struct tile{

    Uint8 id;
    SDL_Surface *tileTexture;
    SDL_bool isCollision; //プレイヤーなどが衝突するかどうか

}Tile;

void load_tile(void); //グローバル変数tiles[]にタイルの情報を格納

extern Tile *tiles[TILE_KIND];

extern SDL_Rect tileRect;

#endif