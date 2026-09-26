#ifndef DISPLAY_BUFFER_H
#define DISPLAY_BUFFER_H

#include <SDL3/SDL.h>

class display_buffer {
private:
    static constexpr int HEIGHT = 64;
    static constexpr int WIDTH = 128;
    bool pixel_grid[HEIGHT][WIDTH] = {false};

public:
    void set_pixel(int x, int y, bool state);
    void render_screen(SDL_Renderer* ren);
    void clear_screen();
};

#endif