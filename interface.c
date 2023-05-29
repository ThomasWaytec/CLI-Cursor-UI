
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

static const COORD TOP_LEFT_CURSOR_POSITION = {0, 0};

    
size_t* get_largest_per_column(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid) {

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

void draw_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, bool padding) {
    
    size_t* largest_per_column = get_largest_per_column(GRID_HEIGHT, GRID_LENGTH, grid);

    size_t full_padding_length;
    size_t padding_length_by_side;

    char* text;
    size_t text_length;
    bool is_odd_length;

    for (size_t row = 0; row < GRID_HEIGHT; row++)
    {
        for (size_t column = 0; column < GRID_LENGTH; column++)
        {  
            text = grid[row][column];
            text_length = strlen(text);
            is_odd_length = (text_length % 2);
            //text_length += is_odd_length;

            full_padding_length = largest_per_column[column] - strlen(text);

            padding_length_by_side = (full_padding_length)/2;
            
            
            //printf("column=%d\n", column);printf("len_text=%d\n", strlen(text));printf("largest_per_column=%d\n", largest_per_column[column]);printf("text=%s\n", grid[row][column]);printf("full_padding_length=%d\n", full_padding_length);printf("padding_length_by_side=%d\n", padding_length_by_side);printf("\n");
            

            printf("%*s%s%*s|", padding_length_by_side, "", text, padding_length_by_side + (full_padding_length % 2), "");

        }
        
        printf("\n");
    }

}

/*
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
*/

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

    for (size_t row = 0; row < GRID_HEIGHT; row++)
    {
        grid[row] = calloc(GRID_LENGTH, __SIZEOF_POINTER__);

        for (size_t column = 0; column < GRID_LENGTH; column++)
        {   
            grid[row][column] = "test";
        }
        
    }
    grid[0][0] = "ev  en";
    grid[1][1] = "111";
    grid[2][2] = "LoLoLoLoLoLoLoLoLoLoLoLoo";

    
    //system("cls||clear");
    draw_grid(GRID_HEIGHT, GRID_LENGTH, grid, false);


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
