#include <stdio.h>
#include <iostream>

class display_buffer{
    private:
        static constexpr int HEIGHT = 64;
        static constexpr int WIDTH = 128;
        bool pixel_grid[HEIGHT][WIDTH] = {false}; // screen 


    public:
        void set_pixel(int y, int x, bool state) {
            if (y > 64 || y < 0) return; // stops the method from 
            if (x > 128 || x < 0) return; 
            if (pixel_grid[y][x] == state) return; // checks if the state is the same to the one we're setting it to

            pixel_grid[y][x] = {state}; // change the state of the pixel to the desired value (true or false which is basically on or off)
        }

        void render_screen() {
            for (int i = 0; i < HEIGHT; i++) { // height
                for (int j = 0; j < WIDTH; j++) { // width
                    printf("%d", pixel_grid[i][j]);
                }
                printf("\n");
            }
        }

        void clear_screen() {
            for (int i = 0; i < HEIGHT; i++) { // height
                for (int j = 0; j < WIDTH; j++) { // width
                    pixel_grid[i][j] = false; // turn all the on pixels to off
                }
            }
        }
};