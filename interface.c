
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

static const COORD TOP_LEFT_CURSOR_POSITION = {0, 0};

    


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


/*
// Test/Usage
int main(void) {



    // setup key mapping
    Key key_mapping[KEY_MAPPING_LENGHT] = {

        [ARROW_UP] = {.add_to_x_coord = 0, .add_to_y_coord = 1, .terminate_loop = false},
        [ARROW_DOWN] = {.add_to_x_coord = 0, .add_to_y_coord = -1, .terminate_loop = false},
        [ARROW_RIGHT] = {.add_to_x_coord = 1, .add_to_y_coord = 0, .terminate_loop = false},
        [ARROW_LEFT] = {.add_to_x_coord = -1, .add_to_y_coord = 0, .terminate_loop = false},

        ['a'] = {.add_to_x_coord = 1, .add_to_y_coord = 1, .terminate_loop = false},
        ['b'] = {.add_to_x_coord = 2, .add_to_y_coord = 2, .terminate_loop = false},
        ['c'] = {.add_to_x_coord = -3, .add_to_y_coord = -3, .terminate_loop = false},

        [ENTER_KEY] {.add_to_x_coord = 0, .add_to_y_coord = 0, .terminate_loop = true}        
    };

    
    
    // set up cursor
    Cursor cursor = {
        .x_coord = 0,
        .x_coord_min = 0,
        .x_coord_max = 9,

        .y_coord = 0,
        .y_coord_min = 0,
        .y_coord_max = 9,
    };


    bool terminate_loop = false;
    while (!process_user_input(&cursor, key_mapping, &terminate_loop)) {
        
        printf("%d %d\n", cursor.x_coord, cursor.y_coord);
        //printf("cursor.x_coord=%d\n", cursor.x_coord);
        //printf("cursor.y_coord=%d\n", cursor.y_coord);
    }

    return 0;
}

*/
