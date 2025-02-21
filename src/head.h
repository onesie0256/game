/**
 * ヘッダファイルをここにまとめる
 */
#ifndef HEAD_H
#define HEAD_H

//標準
#include <stdio.h>

//SDL関連
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL/SDL_gfxPrimitives.h>
//#include <SDL/SDL_net.h>

//srcディレクトリ
#include "colors.h"
#include "definitions.h"
#include "globals.h"
#include "sprite.h"
#include "map.h"

//objectディレクトリ
#include "objects/player.h"
#include "objects/tiles.h"



//scenesディレクトリ
#include "scenes/title.h"
#include "scenes/main_game.h"

//utilディレクトリ
#include "util/image_utils.h"
#include "util/key_and_mouse_utils.h"
#include "util/string_tex_util.h"

//uiディレクトリ
#include "ui/menu.h"


#endif