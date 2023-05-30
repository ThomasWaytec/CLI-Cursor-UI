#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "interface.h"


char* get_user_chosen_grid_size(void) {
    
    /* define the grid dimensions */
    const size_t GRID_HEIGHT = 3;
    const size_t GRID_LENGTH = 3;

    /* allocating space for the grid */
    char*** grid = calloc(GRID_HEIGHT, __SIZEOF_POINTER__);    
    for (size_t row = 0; row < GRID_HEIGHT; row++) {grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);}
    

    /* initializing the grid */
    const size_t LONGEST_STRING_LENGTH_IN_GRID = 3;
    grid[0][0] = "1x1"; grid[0][1] = "2x2"; grid[0][2] = "3x3";
    grid[1][0] = "4x4"; grid[1][1] = "5x5"; grid[1][2] = "6x6";
    grid[2][0] = "7x7"; grid[2][1] = "8x8"; grid[2][2] = "9x9";


    /* get the chosen value from the user */
    Cursor cursor = emulate_grid(GRID_HEIGHT, GRID_LENGTH, grid);

    /* return chosen value */
    char* chosen_grid_size = calloc(LONGEST_STRING_LENGTH_IN_GRID + 1, sizeof(char));
    chosen_grid_size = grid[cursor.x_coord][cursor.y_coord];
    return chosen_grid_size;

}

int main(void) {

    
    // hide Windows terminal cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(STD_HANDLE, &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(STD_HANDLE, &cursorInfo);


    return 0;
}


