#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ESCAPE_VALUE 224
#define ESCAPE_VALUE_NUM_PAD 0 
#define ESC_KEY 27
#define SPACE_KEY 32
#define ENTER_KEY 13
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

#define BUTTON_MAPPING_LENGHT 255





void process_user_input(const int MIN, const int MAX, int* value_to_modify, const int* button_mapping) {
    
    
    if (!kbhit()) {return;}

    char user_key;
    user_key = getch();
    if (user_key == ESCAPE_VALUE || user_key == ESCAPE_VALUE_NUM_PAD) {user_key = getch();}


    int modified_value = (*value_to_modify) + button_mapping[user_key];
    if (modified_value < MIN) {modified_value = MIN;}
    if (modified_value > MAX) {modified_value = MAX;}

    (*value_to_modify) = modified_value;


    
}


// Test/Usage
int main(void) {


    // create button mapping
    int button_mapping[BUTTON_MAPPING_LENGHT] = {0};
    button_mapping['a'] = 1;
    button_mapping['b'] = 2;
    button_mapping['c'] = -1;
    button_mapping[ENTER_KEY] = 10;
    button_mapping[SPACE_KEY] = -10;

    // create cursor
    int* cursor = calloc(1, __SIZEOF_INT__);
    (*cursor) = 0;


    while (1) {
        process_user_input(0, 9, cursor, button_mapping);
        printf("cursor=%d\n", *cursor);
        Sleep(1 * 1000);
    }

    return 0;
}