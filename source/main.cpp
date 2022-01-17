#include <stdio.h>

// Third-party library
#include <SDL.h>

int main(int argc, char* argv[]){
    SDL_Window *window;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("ERROR: window could not load\n\t%s", SDL_GetError());
        exit(1);
    }else{
        printf("The window is running\n");
    }

    window = SDL_CreateWindow(
            "My SDL window",
            20,
            20,
            640,
            480,
            SDL_WINDOW_SHOWN
            );

    bool isRunning = true;
    while(isRunning){
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type){
                case SDL_QUIT:
                    isRunning = false;
                default:
                    continue;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
