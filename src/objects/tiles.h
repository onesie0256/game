#ifndef TILES_H
#define TILES_H
#include "../head.h"
#define TILE_KIND 3
#define TILE_SIZE 64

typedef enum tile_name{
    unknownTile,
    emptyTile,
    collision_tile
}Tile_name;

typedef struct tile{

    Uint8 id;
    char *tileName;
    SDL_Texture *tileTexture;
    SDL_bool isCollision; //プレイヤーなどが衝突するかどうか

}Tile;

int load_tile(void); //グローバル変数tiles[]にタイルの情報を格納

void free_tiles(void);

extern Tile *tiles[TILE_KIND];

extern SDL_Rect tileRect;


#endif