/* 
Resources:

    GetConsoleScreenBufferInfo:
        https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows

*/

#include <stdio.h>
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


void draw_grid(const size_t grid_size, const char** grid) {
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

int main(void) {
    
    const size_t grid_size = 3;
    char** grid = calloc(grid_size, __SIZEOF_POINTER__);
    // fill the grid
    for (size_t i = 0; i < grid_size; i++) {grid[i] = "test";}
    

    // draw grid
    draw_grid(grid_size, grid);
    
    

    return 0;
}