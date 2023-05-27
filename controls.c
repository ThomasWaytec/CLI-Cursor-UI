#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#include "controls.h"


void process_user_input(const int MIN, const int MAX, int* value_to_modify, const int* key_mapping) {
    
    
    if (!kbhit()) {return;}

    char user_key;
    user_key = getch();
    if (user_key == ESCAPE_VALUE || user_key == ESCAPE_VALUE_NUM_PAD) {user_key = getch();}


    int modified_value = (*value_to_modify) + key_mapping[user_key];
    if (modified_value < MIN) {modified_value = MIN;}
    if (modified_value > MAX) {modified_value = MAX;}

    (*value_to_modify) = modified_value;


    
}


/*
// Test/Usage
int main(void) {


    // create key mapping
    int key_mapping[key_MAPPING_LENGHT] = {0};
    key_mapping['a'] = 1;
    key_mapping['b'] = 2;
    key_mapping['c'] = -1;
    key_mapping[ENTER_KEY] = 10;
    key_mapping[SPACE_KEY] = -10;

    // create cursor
    int* cursor = calloc(1, __SIZEOF_INT__);
    (*cursor) = 0;


    while (1) {
        process_user_input(0, 9, cursor, key_mapping);
        printf("cursor=%d\n", *cursor);
        Sleep(1 * 1000);
    }

    return 0;
}
*/

void mod_key_property(key_properties* key_property) {

    key_property->add_to_x_coord += 1;
    key_property->add_to_y_coord += 3;
    key_property->terminate_loop = true;

}

/* this struct to be passed by value in order to make it mutable
int main(void) {

    
    key_properties key_property = {0, 0, false};

    printf("add_to_x_coord=%d\n", key_property.add_to_x_coord);
    printf("add_to_y_coord=%d\n", key_property.add_to_y_coord);
    printf("terminate_loop=%d\n", key_property.terminate_loop);

    mod_key_property(&key_property);

    printf("add_to_x_coord=%d\n", key_property.add_to_x_coord);
    printf("add_to_y_coord=%d\n", key_property.add_to_y_coord);
    printf("terminate_loop=%d\n", key_property.terminate_loop);



    return 0;
    
}
*/