#include "tiles.h"
#include <errno.h>


int load_tile(void) {
    FILE *tileDataFile = fopen("src/objects/tile_data.csv", "r");
    if (tileDataFile == NULL) {
        printf("タイルデータファイルを開けません: %s\n", strerror(errno));
        return 0; // エラー処理
    }

    char line[256]; // 行を格納するバッファ
    fgets(line, sizeof(line), tileDataFile); // ヘッダー行をスキップ

    for (int i = 0; i < TILE_KIND; i++) {
        if (fgets(line, sizeof(line), tileDataFile) == NULL) {
            break; // EOFまたはエラー
        }

        // CSVの各フィールドを解析
        Uint8 id;
        char tileName[30];
        char texturePath[30];
        int isCollisionTemp;
        char fullPath[45]; // 適切なサイズを指定


        // CSVの行をカンマで分割
        sscanf(line, "%hhu,%29[^,],%99[^,],%d,", &id, tileName, texturePath, &isCollisionTemp);

        snprintf(fullPath, sizeof(fullPath), "assets/img/%s", texturePath);

        // Tile構造体のメモリを確保
        Tile *tile = (Tile *)malloc(sizeof(Tile));
        tile->id = id;
        tile->tileName = strdup(tileName); // タイル名をコピー
        tile->tileTexture = SDL_CreateTextureFromSurface(renderer ,  SDL_LoadBMP(fullPath)); // テクスチャを読み込む
        tile->isCollision = (isCollisionTemp == 1) ? SDL_TRUE : SDL_FALSE;

        // tiles配列に格納
        tiles[i] = tile;
    }

    fclose(tileDataFile);
    return 1; // 成功
}

void free_tiles(void)
{
    Tile *p;
    for (int i = 0 ; i < TILE_KIND ; i++){
        p = tiles[i];
        free(p->tileName);
        SDL_DestroyTexture(p->tileTexture);
        free(p);
    }
}