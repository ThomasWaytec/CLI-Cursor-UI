#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#include "controls.h"


bool process_user_input(Cursor* cursor, const Key* key_mapping, bool* terminate_loop) {
    
    /* if there's a key value in the buffer*/
    if (!kbhit()) {return false;}

    
    char pressed_key;
    pressed_key = getch();
    /* some keys send an escape value and then the actual value */
    if (pressed_key == ESCAPE_VALUE || pressed_key == ESCAPE_VALUE_NUM_PAD) {pressed_key = getch();}

    
    
    Key mapped_pressed_key = key_mapping[pressed_key];
    cursor->x_coord += mapped_pressed_key.add_to_x_coord;
    cursor->y_coord += mapped_pressed_key.add_to_y_coord;

    // cursor x and y coord bounds check
    if (cursor->x_coord < cursor->x_coord_min) {cursor->x_coord = cursor->x_coord_min;}
    if (cursor->x_coord > cursor->x_coord_max) {cursor->x_coord = cursor->x_coord_max;}

    if (cursor->y_coord < cursor->y_coord_min) {cursor->y_coord = cursor->y_coord_min;}
    if (cursor->y_coord > cursor->y_coord_max) {cursor->y_coord = cursor->y_coord_max;}
    
    *terminate_loop = mapped_pressed_key.terminate_loop;
    
    return *terminate_loop;
    
}



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


