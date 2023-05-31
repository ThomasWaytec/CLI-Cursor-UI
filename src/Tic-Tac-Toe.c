#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "interface.h"

void hide_terminal_cursor(void) {

    /* hide Windows terminal cursor */
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(STD_HANDLE, &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(STD_HANDLE, &cursorInfo);

}

char* get_user_chosen_grid_size(void) {
    
    /* define the grid dimensions */
    const size_t GRID_HEIGHT = 7;
    const size_t GRID_LENGTH = 1;

    /* allocating space for the grid */
    char*** grid = calloc(GRID_HEIGHT, __SIZEOF_POINTER__);    
    for (size_t row = 0; row < GRID_HEIGHT; row++) {grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);}
    

    /* initializing the grid */
    const size_t LONGEST_STRING_LENGTH_IN_GRID = 3;
    grid[0][0] = "3x3";
    grid[1][0] = "4x4";
    grid[2][0] = "5x5";
    grid[3][0] = "6x6";
    grid[4][0] = "7x7";
    grid[5][0] = "8x8";
    grid[6][0] = "9x9";


    /* get the chosen value from the user */
    Cursor cursor = live_grid(GRID_HEIGHT, GRID_LENGTH, grid);

    /* return chosen value */
    char* chosen_grid_size = grid[cursor.x_coord][cursor.y_coord];
    return chosen_grid_size;

}


int main(void) {
    
    hide_terminal_cursor();

    
    char* chosen_grid_size = get_user_chosen_grid_size();
    int grid_size = chosen_grid_size[0] - '0'; /* get grid size as integer*/



    /* create game grid of chosen size */
    const size_t GRID_HEIGHT = grid_size;
    const size_t GRID_LENGTH = grid_size;

    char*** game_grid = calloc(GRID_HEIGHT, __SIZEOF_POINTER__); /* allocating space for the grid */

    for (size_t row = 0; row < GRID_HEIGHT; row++) {
        game_grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);

        for (size_t column = 0; column < GRID_LENGTH; column++)
        {
            game_grid[row][column] = " ";     /* initializing the grid */
        }
    }


    Cursor cursor;
    bool game_end = false;
    while (!game_end)
    {
        cursor = live_grid(GRID_HEIGHT, GRID_LENGTH, game_grid);
        game_grid[cursor.x_coord][cursor.y_coord] = "X";

        cursor = live_grid(GRID_HEIGHT, GRID_LENGTH, game_grid);
        game_grid[cursor.x_coord][cursor.y_coord] = "O";
        
    }
    
    return 0;
}


