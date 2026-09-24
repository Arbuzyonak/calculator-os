#ifndef DISPLAY_BUFFER_H
#define DISPLAY_BUFFER_H

class display_buffer {
    private:
        static constexpr int HEIGHT = 64;
        static constexpr int WIDTH = 128;
        bool pixel_grid[HEIGHT][WIDTH] = {false};
    
    public:
        void set_pixel(int y, int x, bool state);
        void render_screen();
        void clear_screen();

};

#endif