#ifndef CONTROLS_H
#define CONTROLS_H

#include <stdbool.h>

#define ESCAPE_VALUE 224
#define ESCAPE_VALUE_NUM_PAD 0 
#define ESC_KEY 27
#define SPACE_KEY 32
#define ENTER_KEY 13
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

#define KEY_MAPPING_LENGHT 255



typedef struct {

    int x_coord;
    int x_coord_min;
    int x_coord_max;

    int y_coord;
    int y_coord_min;
    int y_coord_max;
} Cursor;



typedef struct {

    /* the value to add to the x_coord in the Cursor */
    int add_to_x_coord;
    /* the value to add to the x_coord in the Cursor */
    int add_to_y_coord;
    /* if process_user_input runs in a loop specify which key(s) terminate the loop when pressed */
    bool terminate_loop;
}
KeyProperties;
#endif