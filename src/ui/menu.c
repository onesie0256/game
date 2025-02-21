#include "menu.h"


TTF_Font *fontMenu , *fontOption;
SDL_Texture *menuTex , *menubackTex ,*strMenuTex , *strRuturnTitleTex,*strQuitGameTex;

SDL_Renderer *menuRenderer;

Sprite_node *menuSprite;

void load_menu(void);

void free_menu(void);

int menu(void *data)
{

    Uint8 *mainRunningState = (int *)data;

    int isLoop = 1;
    menuSprite->isDisplay = SDL_TRUE;

    while (isLoop)
    {
        if (SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                isLoop = 0;
                mainRunningState = 2;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if (is_in_square4(SCREEN_WIDTH / 2 , SCREEN_HEIGHT * 6 / 8.0 , SCREEN_WIDTH , SCREEN_HEIGHT * 7 / 8.0 - 1)){
                    isLoop = 0;
                    mainRunningState = 1;
                    

                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE){
                    menuSprite->isDisplay = SDL_FALSE;
                    isMenuOpening = SDL_FALSE;
                    return 0;
                }
                break;

            default:
                break;
            }
        }

        SDL_Delay(10);
    }
    

    


    return 0;
}

void load_menu(void)
{

    fontMenu = TTF_OpenFont("./assets/fonts/azuki.ttf", 60);
    fontOption = TTF_OpenFont("./assets/fonts/azuki.ttf", 60);

    menuRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    


    menuTex = SDL_CreateTexture(menuRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    SDL_Surface *menuback = SDL_LoadBMP("assets/img/ui/menu_back.bmp");
    menubackTex = SDL_CreateTextureFromSurface(menuRenderer , menuback);



    SDL_SetRenderTarget(menuRenderer, menuTex);
    

    SDL_Rect *menuSrcRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    menuSrcRect->x = 0;
    menuSrcRect->y = 0;
    menuSrcRect->w = menuback->w;
    menuSrcRect->h = menuback->h;

    SDL_Rect *menuDstRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    menuDstRect->x = SCREEN_WIDTH / 2;
    menuDstRect->y = 0;
    menuDstRect->w = menuback->w;
    menuDstRect->h = menuback->h;

    SDL_Surface *strRuturnTitle = TTF_RenderText_Blended(fontOption , "タイトルに戻る" , colors_white);
    strRuturnTitleTex = SDL_CreateTextureFromSurface(renderer , strRuturnTitle);
    SDL_Rect sRTsrc = {.x = 0 , .y = 0 , .w = strRuturnTitle->w , .h = strRuturnTitle->h};
    SDL_Rect sRTdst = {.x = SCREEN_WIDTH / 2 , .y = SCREEN_HEIGHT * 6 / 8.0 , .w = strRuturnTitle->w , .h = strRuturnTitle->h};
    
    SDL_RenderCopy(menuRenderer , menubackTex , menuSrcRect , menuSrcRect);
    SDL_RenderCopy(menuRenderer , strRuturnTitleTex , &sRTsrc , &sRTdst);

    menuSprite = add_group(UI2 , 101 , SDL_FALSE , menuSrcRect , menuDstRect , menuTex);

}

void free_menu(void)
{

}
