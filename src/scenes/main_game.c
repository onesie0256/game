#include "main_game.h"

int main_game(void)
{
    load_main_game();
    //SDL_EnableKeyRepeat(10 , 10);
    
    while (1){
        if (SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                return 0;
                break;
            
            /*case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                
                case SDLK_d:
                    player_move(East);
                    break;
                
                case SDLK_a:
                    player_move(West);
                    break;

                case SDLK_w:
                    player_move(North);
                    break;
                
                case SDLK_s:
                    player_move(South);
                    break;
                
                default:
                    break;
                }*/
            default:
                break;
            }
        }
        const Uint8 *state = SDL_GetKeyState(NULL);
             if (state[SDLK_w] && state[SDLK_d]) player_move(NorthEast);
        else if (state[SDLK_w] && state[SDLK_a]) player_move(NorthWest);
        else if (state[SDLK_s] && state[SDLK_d]) player_move(SouthEast);
        else if (state[SDLK_s] && state[SDLK_a]) player_move(SouthWest);
        else if (state[SDLK_w]) player_move(North);
        else if (state[SDLK_a]) player_move(West);
        else if (state[SDLK_s]) player_move(South);
        else if (state[SDLK_d]) player_move(East);
    
        update(window);
        SDL_Flip(window);
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