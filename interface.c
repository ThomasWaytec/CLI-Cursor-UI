
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"

#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

const int BASE_PADDING = 3;
static const COORD TOP_LEFT_CURSOR_POSITION = {0, 0};

    
static size_t* get_largest_per_column(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid) {

    size_t* largest_per_column = calloc(GRID_LENGTH, sizeof(size_t));
    size_t largest;
    size_t current;
     

    for (size_t row = 0; row < GRID_HEIGHT; row++)
    {
         
        for (size_t column = 0; column < GRID_LENGTH; column++)
        {
            largest = largest_per_column[column];
            current = strlen(grid[row][column]);
          
            if (current > largest) {largest = current;}
            largest_per_column[column] = largest;        
        }    
    }

    return largest_per_column;

}

void draw_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, const size_t BASE_PADDING) {
    
    size_t* largest_per_column = get_largest_per_column(GRID_HEIGHT, GRID_LENGTH, grid);

    size_t full_padding_length;
    size_t left_padding_length;
    size_t right_pading_length;

    char* text;
    size_t text_length;

    for (size_t row = 0; row < GRID_HEIGHT; row++)
    {
        for (size_t column = 0; column < GRID_LENGTH; column++)
        {  
            text = grid[row][column];
            text_length = strlen(text);

            full_padding_length = largest_per_column[column] - strlen(text);
            
            left_padding_length = BASE_PADDING + full_padding_length/2;
            right_pading_length = BASE_PADDING + full_padding_length/2 + (full_padding_length % 2);
                

            printf("%*s%s%*s|", left_padding_length, "", text, right_pading_length, "");
        }
        
        printf("\n");
    }

}

void draw_grid_with_cursor(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, Cursor cursor) {

    
    char* temp = grid[cursor.x_coord][cursor.y_coord];
    size_t visual_cursor_length = strlen(temp);

    /* create visual cursor */
    char* visual_cursor = calloc(visual_cursor_length, sizeof(char) + 1);    
    for (size_t i = 0; i < visual_cursor_length; i++) {visual_cursor[i] = ' ';}




    /* render 2 framses */
    grid[cursor.x_coord][cursor.y_coord] = visual_cursor;
    SetConsoleCursorPosition(STD_HANDLE, TOP_LEFT_CURSOR_POSITION);    
    draw_grid(GRID_HEIGHT, GRID_LENGTH, grid, BASE_PADDING);

    Sleep(3);

    grid[cursor.x_coord][cursor.y_coord] = temp;
    SetConsoleCursorPosition(STD_HANDLE, TOP_LEFT_CURSOR_POSITION);
    draw_grid(GRID_HEIGHT, GRID_LENGTH, grid, BASE_PADDING);

}

Cursor emulate_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid) {

    
    /* setup key mapping */
    Key key_mapping[KEY_MAPPING_LENGHT] = {

        [ARROW_UP] = {.add_to_x_coord = -1, .add_to_y_coord = 0, .terminate_loop = false},
        [ARROW_DOWN] = {.add_to_x_coord = 1, .add_to_y_coord = 0, .terminate_loop = false},
        [ARROW_RIGHT] = {.add_to_x_coord = 0, .add_to_y_coord = 1, .terminate_loop = false},
        [ARROW_LEFT] = {.add_to_x_coord = 0, .add_to_y_coord = -1, .terminate_loop = false},

        ['w'] = {.add_to_x_coord = -1, .add_to_y_coord = 0, .terminate_loop = false},
        ['s'] = {.add_to_x_coord = 1, .add_to_y_coord = 0, .terminate_loop = false},
        ['d'] = {.add_to_x_coord = 0, .add_to_y_coord = 1, .terminate_loop = false},
        ['a'] = {.add_to_x_coord = 0, .add_to_y_coord = -1, .terminate_loop = false},

        
        [ENTER_KEY] {.add_to_x_coord = 0, .add_to_y_coord = 0, .terminate_loop = true}        
    };

    /* initialize cursor */
    Cursor cursor = {
        .x_coord = 0,
        .x_coord_min = 0,
        .x_coord_max = GRID_HEIGHT - 1,

        .y_coord = 0,
        .y_coord_min = 0,
        .y_coord_max = GRID_LENGTH - 1,
    };
    
    system("cls");
    printf("cos");
    while (!process_user_input(&cursor, key_mapping)) {draw_grid_with_cursor(GRID_HEIGHT, GRID_LENGTH, grid, cursor);}
    system("cls");


    return cursor;
}


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
