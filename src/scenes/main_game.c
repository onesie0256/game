#include "main_game.h"

int main_game(void)
{
    load_main_game();
    //SDL_EnableKeyRepeat(10 , 10);
    Uint8 runningState = 0;

    isMenuOpening = SDL_FALSE;



    while (runningState == 0){

        
        if (isMenuOpening == SDL_FALSE){
            if (SDL_PollEvent(&event)){
                switch (event.type)
                {
                case SDL_QUIT:
                    free_main_game();
                    return 0;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        SDL_Thread *menuThr;
                        menuThr = SDL_CreateThread(menu, "nemuThr", &runningState);
                        SDL_DetachThread(menuThr);
                        isMenuOpening = SDL_TRUE;
                        
                        break;

                        default:
                        break;
                    
                    }
                }
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
                 if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D]) player_move(NorthEast);
            else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A]) player_move(NorthWest);
            else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D]) player_move(SouthEast);
            else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A]) player_move(SouthWest);
            else if (state[SDL_SCANCODE_W]) player_move(North);
            else if (state[SDL_SCANCODE_A]) player_move(West);
            else if (state[SDL_SCANCODE_S]) player_move(South);
            else if (state[SDL_SCANCODE_D]) player_move(East);
        }
        update();
        //SDL_Flip(window);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    free_main_game();

    if (runningState == 1){
        return 1;
    }
    
    return 0;
}

int load_main_game(void)
{
    player = load_player();
    sprite_init();
    load_map();
    add_group(PLAYER , 1 ,SDL_TRUE , player->textureRect , player->rect , player->playerTexture);
    load_menu();
    return 1;
}

void free_main_game(void)
{
    free_group();
    free_player();
    free_tiles();
}