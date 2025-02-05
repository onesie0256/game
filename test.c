#include "src/head.h"



int main(int argc , char *argv[])
{
    TTF_Init();



    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("failed to initializde SDL \n");
        exit(-1);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , 2 , 1024) < 0){
        printf("failed to initializde SDL_mixer\n");
        exit(-1);
    }

    if ((window = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE)) == NULL){
        printf("failed to initialize videomode. \n%s\n" , Mix_GetError());
        exit(-1);
    }
    //ウィンドウ設定
    SDL_WM_SetCaption("test", "test");
    SDL_Surface *icon = SDL_LoadBMP("icon.bmp");
    if (icon == NULL) {
        printf("アイコンの読み込みに失敗しました: %s\n", SDL_GetError());
    } else {
        SDL_WM_SetIcon(icon, NULL);
        //SDL_FreeSurface(icon);  // アイコンのサーフェスを解放
    }
    
    title();
    
    SDL_FreeSurface(window);
    SDL_FreeSurface(icon);

    SDL_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}




