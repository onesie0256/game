#include "main_game.h"

int main_game(void)
{
    load_main_game();

    while (1){
        if (SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                return 0;
                break;
            
            default:
                break;
            }
        }
    
        update(window);
        SDL_Flip(window);
        SDL_Delay(100);
    }
}

int load_main_game(void)
{
    Player *player = load_player();
    sprite_init();
    add_middle(PLAYER , 1 , player->textureRect , player->rect , player->playerTexture);
    return 1;
}