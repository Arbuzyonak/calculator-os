#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow("Calculator OS", 1280, 640, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);
    
    // Scale everything up 10x automatically
    SDL_SetRenderScale(ren, 10.0f, 10.0f);

    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    if (ren == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare { 10.0f, 10.0f, 50.0f, 30.0f };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(ren); // Clear the renderer

        SDL_SetRenderDrawColor(ren, 0, 255, 0, 255); // Set render draw color to green
        SDL_RenderFillRect(ren, &greenSquare); // Render the rectangle
        
        SDL_RenderPresent(ren); // Render the screen
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}