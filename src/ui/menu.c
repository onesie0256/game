#include "menu.h"


TTF_Font *fontMenu , *fontOption;
SDL_Texture *menuTex , *menubackTex;
String_Texture *strMenuTex , *strReturnTitleTex,*strQuitGameTex;

Sprite_node *menuSprite;

void free_menu(void);

int menu(void *data)
{

    Uint8 *mainRunningState = (Uint8 *)data;

    int isLoop = 1;
    menuSprite->isDisplay = SDL_TRUE;

    while (isLoop)
    {
        if (SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                isLoop = 0;
                *mainRunningState = 2;
                free_menu();
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if (is_in_square4(SCREEN_WIDTH / 2 , SCREEN_HEIGHT * 6 / 8.0 , SCREEN_WIDTH , SCREEN_HEIGHT * 7 / 8.0 - 1)){
                    isLoop = 0;
                    *mainRunningState = 1;
                    

                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE){
                    menuSprite->isDisplay = SDL_FALSE;
                    free_menu();
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

    //fontMenu = TTF_OpenFont("./assets/fonts/azuki.ttf", 60);
    //fontOption = TTF_OpenFont("./assets/fonts/azuki.ttf", 60);

    //menuRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    


    menuTex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    SDL_Surface *menuback = SDL_LoadBMP("assets/img/ui/menu_back.bmp");
    menubackTex = SDL_CreateTextureFromSurface(renderer , menuback);

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

    
    SDL_Rect sRTdst = {.x = menuback->w * 1 / 3.0 , .y = menuback->h * 6 / 8.0};
    strReturnTitleTex = make_string_tex(1 , colors_white , 60 , "タイトルにもどる" , menuTex , &sRTdst);
    
    SDL_SetRenderTarget(renderer , menuTex);
    SDL_RenderCopy(renderer , menubackTex , menuSrcRect , menuSrcRect);
    SDL_RenderCopy(renderer , strReturnTitleTex->texture , strReturnTitleTex->srcRect , strReturnTitleTex->dstRect);
    SDL_SetRenderTarget(renderer , NULL);


    menuSprite = add_group(UI2 , 101 , SDL_FALSE , menuSrcRect , menuDstRect , menuTex);
    SDL_FreeSurface(menuback);
}

void free_menu(void)
{
    free_string_tex(strReturnTitleTex);

    SDL_DestroyTexture(menubackTex);
}
