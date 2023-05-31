
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "interface.h"

static const int BASE_PADDING = 3;
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

static void draw_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, const size_t BASE_PADDING) {
    
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

            full_padding_length = largest_per_column[column] - text_length;
            
            left_padding_length = BASE_PADDING + full_padding_length/2;
            right_pading_length = BASE_PADDING + full_padding_length/2 + (full_padding_length % 2);
                

            printf("%*s%s%*s|", left_padding_length, "", text, right_pading_length, "");
        }
        
        printf("\n");
    }

}

static void draw_grid_with_cursor(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, Cursor cursor) {

    
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
    while (!process_user_input(&cursor, key_mapping)) {draw_grid_with_cursor(GRID_HEIGHT, GRID_LENGTH, grid, cursor);}
    system("cls");


    return cursor;
}
