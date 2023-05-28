#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#include "controls.h"


bool process_user_input(Cursor* cursor, const Key* key_mapping, bool* terminate_loop) {
    
    /* if there isn't a key value in the buffer */
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

