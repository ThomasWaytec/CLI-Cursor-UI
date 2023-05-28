#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#include "controls.h"

/*
void process_user_input(Cursor* cursor, const Key* key_mapping[KEY_MAPPING_LENGHT]) {
    
    
    if (!kbhit()) {return;}

    char user_key;
    user_key = getch();
    if (user_key == ESCAPE_VALUE || user_key == ESCAPE_VALUE_NUM_PAD) {user_key = getch();}


    int modified_value = (*value_to_modify) + key_mapping[user_key];
    if (modified_value < MIN) {modified_value = MIN;}
    if (modified_value > MAX) {modified_value = MAX;}

    (*value_to_modify) = modified_value;


    
}
*/


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

    
    return 0;
}


