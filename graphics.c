/* 
Resources:

    GetConsoleScreenBufferInfo:
        https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows

    SetConsoleCursorPosition:
        https://stackoverflow.com/questions/73682672/why-are-console-graphics-so-slow-in-c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>




void print_terminal_dimensions(void) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    while (1) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        printf("columns: %d\n", columns);
        printf("rows: %d\n", rows);
        printf("\n");
        Sleep(3 * 1000);
    }

}


void draw_grid(size_t grid_size, char** grid) {

    size_t i;
    for (i = 0; i < grid_size; i++)
    {
        printf("|");
        for (size_t j = 0; j < strlen(grid[i]); j++) {printf("-");}
        printf("|");
        printf("\n");

        printf("|%s|\n", grid[i]);

    }
    printf("|");
    for (size_t j = 0; j < strlen(grid[i - 1]); j++) {printf("-");}
    printf("|");

}

void draw_grid_with_cursor(size_t grid_size, char** grid, size_t cursor_position) {

    

    char* temp = grid[cursor_position];
    size_t cursor_size = strlen(temp);

    // create cursor
    char* cursor = calloc(cursor_size, sizeof(char) + 1);
    
    for (size_t i = 0; i < cursor_size; i++) {cursor[i] = '_';}

    grid[cursor_position] = cursor;
    draw_grid(grid_size, grid);

    Sleep(10);

    grid[cursor_position] = temp;
    draw_grid(grid_size, grid);
}

int main(void) {
    
    const size_t grid_size = 3;
    char** grid = calloc(grid_size, __SIZEOF_POINTER__);
    // fill the grid
    for (size_t i = 0; i < grid_size; i++) {grid[i] = "test";}
    
    while (1) {
        // draw grid with cursor
        draw_grid_with_cursor(grid_size, grid, 0);
    }
    

    return 0;
}