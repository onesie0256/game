#include "main_game.h"

int main_game(void)
{
    load_main_game();
    //SDL_EnableKeyRepeat(10 , 10);
    
    while (1){

        SDL_bool isMenuOpening = SDL_FALSE;
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
                        //SDL_Thread *menuThr;
                        //menuThr = SDL_CreateThread(menu , (void *)window);
                        //isMenuOpening = SDL_TRUE;
                        
                        //menu(window);
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
}

int load_main_game(void)
{
    player = load_player();
    sprite_init();
    load_map();
    add_group(PLAYER , 1 , player->textureRect , player->rect , player->playerTexture);
    return 1;
}

void free_main_game(void)
{
    free_group();
    free_player();
    free_tiles();
}