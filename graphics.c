/* 
Resources:

    GetConsoleScreenBufferInfo:
        https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows

    SetConsoleCursorInfo:
        https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt

    SetConsoleCursorPosition:
        https://stackoverflow.com/questions/73682672/why-are-console-graphics-so-slow-in-c

    Moderate windows terminal flickering:
        https://stackoverflow.com/questions/34842526/update-console-without-flickering-c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

static const COORD TOP_LEFT_CURSOR_POSITION = {0, 0};

    
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
    printf("\n");

}

void draw_grid_with_cursor(size_t grid_size, char** grid, size_t cursor_position) {

    

    char* temp = grid[cursor_position];
    size_t cursor_size = strlen(temp);

    // create cursor
    char* cursor = calloc(cursor_size, sizeof(char) + 1);    
    for (size_t i = 0; i < cursor_size; i++) {cursor[i] = ' ';}


    grid[cursor_position] = cursor;
    draw_grid(grid_size, grid);

    Sleep(5);

    SetConsoleCursorPosition(STD_HANDLE, TOP_LEFT_CURSOR_POSITION);
    grid[cursor_position] = temp;
    draw_grid(grid_size, grid);

}


size_t parse_arrow_keys(size_t MIN, size_t MAX, size_t cursor_position) {

    if (!kbhit()) {return cursor_position;}

    char user_input = getch();
    if (user_input != 0 && user_input != 224) {return cursor_position;}

    // parse the arrow keys
    switch(getch()) {

        case 72: // Arrow Up
            if (cursor_position == MIN) {return cursor_position;}
            return cursor_position - 1;
            

        case 80: // Arrow Down
            if (cursor_position == MAX) {return cursor_position;}
            return cursor_position + 1;


    }
    return cursor_position;
}

int main(void) {
      
    const size_t grid_size = 3;
    char** grid = calloc(grid_size, __SIZEOF_POINTER__);

    // fill the grid
    for (size_t i = 0; i < grid_size; i++) {grid[i] = "OPTION X";}

    // hide Windows terminal cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(STD_HANDLE, &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(STD_HANDLE, &cursorInfo);



    system("cls||clear");
    // main loop
    size_t cursor_position = 0;
    while (1) {


        draw_grid_with_cursor(grid_size, grid, cursor_position);
        SetConsoleCursorPosition(STD_HANDLE, TOP_LEFT_CURSOR_POSITION);
        
        cursor_position = parse_arrow_keys(0, 2, cursor_position);
        Sleep(1);

    }
    

    return 0;
}
