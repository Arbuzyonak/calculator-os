#include "display_buffer.h"
#include <stdio.h>

void display_buffer::set_pixel(int x, int y, bool state) {
    if (y >= HEIGHT || y < 0) return;
    if (x >= WIDTH || x < 0) return;
    if (pixel_grid[y][x] == state) return;

    pixel_grid[y][x] = state;
}

void display_buffer::render_screen(SDL_Renderer* ren) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (pixel_grid[y][x]) {
                SDL_RenderPoint(ren, static_cast<float>(x), static_cast<float>(y));
            }
        }
    }
}

void display_buffer::clear_screen() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel_grid[y][x] = false;
        }
    }
}