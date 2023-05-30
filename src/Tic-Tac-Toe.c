#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "interface.h"

int main(void) {

    
    // hide Windows terminal cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(STD_HANDLE, &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(STD_HANDLE, &cursorInfo);


    // create grid
    const size_t GRID_HEIGHT = 3;
    const size_t GRID_LENGTH = 3;

    char*** grid = calloc(GRID_HEIGHT, __SIZEOF_POINTER__);
    
    /*
    for (size_t row = 0; row < GRID_HEIGHT; row++)
    {

        grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);

        for (size_t column = 0; column < GRID_LENGTH; column++)
        {   
            //grid[row][column] = "1x1";
        }
    }
    */
    
    for (size_t row = 0; row < GRID_HEIGHT; row++) {grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);}
   
    grid[0][0] = "1x1"; grid[0][1] = "2x2"; grid[0][2] = "3x3";
    grid[1][0] = "4x4"; grid[1][1] = "5x5"; grid[1][2] = "6x6";
    grid[2][0] = "7x7"; grid[2][1] = "8x8"; grid[2][2] = "9x9";


    Cursor cursor = emulate_grid(GRID_HEIGHT, GRID_LENGTH, grid);

    printf("x=%d ", cursor.x_coord);
    printf("y=%d\n", cursor.y_coord);
    printf("%s\n", grid[cursor.x_coord][cursor.y_coord]);    

    return 0;
}


