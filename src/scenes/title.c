#include "title.h"

int title(void)
{
    SDL_Surface *strings , *strNewGame , *strQuitGame; 

    TTF_Font* titleFont , *selectionsFont;
    
    //図形描画
    SDL_FillRect(window , NULL , SDL_MapRGBA(window -> format , 240 , 255 , 255 , 150));
    


    //文字のフォント(仮)
    titleFont = TTF_OpenFont("./assets/fonts/azuki.ttf", TITLE_SIZE);
    selectionsFont = TTF_OpenFont("./assets/fonts/azuki.ttf", 60);
    
    



    Mix_Chunk *seClick1;
    seClick1 = Mix_LoadWAV("./assets/audio/se/click1.wav");
    if (seClick1 == NULL) {
        printf("効果音の読み込みに失敗しました: %s\n", Mix_GetError());
    }
    //Mix_Music *music;
    //music = Mix_LoadMUS("./resources/music/Ethereal.mp3");
    //Mix_PlayMusic(music , 1);
    if (titleFont != NULL){
        strings = TTF_RenderUTF8_Blended(titleFont, TITLE_NAME, colors_black);
        strNewGame = TTF_RenderUTF8_Blended(selectionsFont, "新規ゲーム", colors_black);
        strQuitGame = TTF_RenderUTF8_Blended(selectionsFont, "やめる", colors_black);

        strings = SDL_DisplayFormatAlpha(strings);
        strNewGame = SDL_DisplayFormatAlpha(strNewGame);
        strQuitGame = SDL_DisplayFormatAlpha(strQuitGame);
        
    }

    
    if (strings != NULL && strNewGame != NULL && strQuitGame != NULL) {
        SDL_Rect src_rect = {0 , 0 , strings -> w , strings -> h};
        SDL_Rect dst_rect = {(SCREEN_WIDTH - TITLE_SIZE * strlen(TITLE_NAME)) / 2 , SCREEN_HEIGHT * 1 / 4};
        SDL_Rect ng_src_rect = {0 , 0 , strNewGame -> w , strNewGame -> h};
        SDL_Rect ng_dst_rect = {SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (5 / 8.0)};
        SDL_Rect qg_src_rect = {0 , 0 , strQuitGame -> w , strQuitGame -> h};
        SDL_Rect qg_dst_rect = {SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (7 / 8.0)};


        SDL_BlitSurface(strings, &src_rect, window, &dst_rect);
        SDL_BlitSurface(strNewGame, &ng_src_rect, window, &ng_dst_rect);
        SDL_BlitSurface(strQuitGame, &qg_src_rect, window, &qg_dst_rect);
        
    }
    SDL_Flip(window);
    //SDL_UpdateRect(window , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    //SDL_WM_ToggleFullScreen(window);
    
    //Mix_PlayChannel(1 , seClick1 , 1);

    //SDL_WM_IconifyWindow();
    //SDL_Delay(10000);
    SDL_bool isLoop = SDL_TRUE;
    while(isLoop){
        if(SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_MOUSEMOTION:
                    if(is_in_square(SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (5 / 8.0) , SCREEN_WIDTH , SCREEN_HEIGHT * (7 / 8.0) - 1)){
                        //Mix_PlayChannel(1 , seClick1 , 1);
                        ;
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if(is_in_square(SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (5 / 8.0) , SCREEN_WIDTH , SCREEN_HEIGHT * (6 / 8.0) - 1)){
                        Mix_PlayChannel(-1 , seClick1 , 1);


                        for (int i = 1 ; i <= 100 ; i++){ //0.5秒かけて文字をスライド・透明化
                            

                            //SDL_Color titleStrColor = {0x00 , 0x00 , 0x00 , 0xff -  2.5 * i};
                            SDL_SetAlpha(strings , SDL_SRCALPHA , (int)(255.0 - 2.5 * i));
                            SDL_SetAlpha(strNewGame , SDL_SRCALPHA , (int)(255.0 - 2.5 * i));
                            SDL_SetAlpha(strQuitGame , SDL_SRCALPHA , (int)(255.0 - 2.5 * i));
                            

                            /*
                            SDL_SetColorKey(strings , SDL_SRCCOLORKEY , 0x0);
                            SDL_SetColorKey(strNewGame , SDL_SRCCOLORKEY , 0x0);
                            SDL_SetColorKey(strQuitGame , SDL_SRCCOLORKEY , 0x0);

                            strings = SDL_DisplayFormat(strings);
                            strNewGame = SDL_DisplayFormat(strQuitGame);
                            strQuitGame = SDL_DisplayFormat(strNewGame);
                            */

                            strings = TTF_RenderUTF8_Blended(titleFont, TITLE_NAME , colors_black);
                            strNewGame = TTF_RenderUTF8_Blended(selectionsFont, "新規ゲーム", colors_black);
                            strQuitGame = TTF_RenderUTF8_Blended(selectionsFont, "やめる", colors_black);


                            SDL_Rect src_rect = {0 , 0 , strings -> w , strings -> h};
                            SDL_Rect dst_rect = {(SCREEN_WIDTH - TITLE_SIZE * strlen(TITLE_NAME)) / 2 - SCREEN_WIDTH * i / 200.0 , SCREEN_HEIGHT * 1 / 4};
                            SDL_Rect ng_src_rect = {0 , 0 , strNewGame -> w , strNewGame -> h};
                            SDL_Rect ng_dst_rect = {SCREEN_WIDTH * (5 / 8.0) + SCREEN_WIDTH * i / 200.0 , SCREEN_HEIGHT * (5 / 8.0)};
                            SDL_Rect qg_src_rect = {0 , 0 , strQuitGame -> w , strQuitGame -> h};
                            SDL_Rect qg_dst_rect = {SCREEN_WIDTH * (5 / 8.0) + SCREEN_WIDTH * i / 200.0, SCREEN_HEIGHT * (7 / 8.0)};

                            SDL_FillRect(window , NULL , SDL_MapRGBA(window -> format , 240 , 255 , 255 , 90));
                            SDL_BlitSurface(strings, &src_rect, window, &dst_rect);
                            SDL_BlitSurface(strNewGame, &ng_src_rect, window, &ng_dst_rect);
                            SDL_BlitSurface(strQuitGame, &qg_src_rect, window, &qg_dst_rect);
                            SDL_Flip(window);
                            SDL_Delay(5);
                        }
                        SDL_FreeSurface(strings);
                        SDL_FreeSurface(strNewGame);
                        SDL_FreeSurface(strQuitGame);
                        
                        SDL_Delay(1000);
                        return 1;
                    }
                    else if(is_in_square(SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (7 / 8.0) , SCREEN_WIDTH , SCREEN_HEIGHT)){
                        Mix_PlayChannel(-1 , seClick1 , 2);

                        for (int i = 1 ; i <= 10 ; i++){
                        SDL_Rect src_rect = {0 , 0 , strings -> w , strings -> h};
                        SDL_Rect dst_rect = {(SCREEN_WIDTH - TITLE_SIZE * strlen(TITLE_NAME)) / 2 , SCREEN_HEIGHT * 1 / 4};
                        SDL_Rect ng_src_rect = {0 , 0 , strNewGame -> w , strNewGame -> h};
                        SDL_Rect ng_dst_rect = {SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (5 / 8.0)};
                        SDL_Rect qg_src_rect = {0 , 0 , strQuitGame -> w , strQuitGame -> h};
                        SDL_Rect qg_dst_rect = {SCREEN_WIDTH * (5 / 8.0) , SCREEN_HEIGHT * (7 / 8.0)};


                        SDL_FillRect(window , NULL , SDL_MapRGB(window -> format , 240 - 24 * i , 255- 25 * i , 255- 25 * i));


                        SDL_BlitSurface(strings, &src_rect, window, &dst_rect);
                        SDL_BlitSurface(strNewGame, &ng_src_rect, window, &ng_dst_rect);
                        SDL_BlitSurface(strQuitGame, &qg_src_rect, window, &qg_dst_rect);
                        
                        SDL_UpdateRect(window , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
                        SDL_Delay(100);
                    }
                    SDL_free(strings);
                    SDL_free(strQuitGame);
                    SDL_free(strNewGame);
                    return 0;
                    }
                break;
            }
        }
    }
    return 0;
}
