
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ESC_KEY 27
#define SPACE_KEY 32
#define ENTER_KEY 13
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

#define ESCAPE_VALUE 224
#define ESCAPE_VALUE_NUM_PAD 0 

#define BUTTON_MAPPING_LENGHT 127




void dummy_function(int* dummy_value) {return;}

/* key = index in array; value = function pointer; */
/* to access a value, example: button_mapping['a'] */
typedef void* BUTTON_MAPPING[BUTTON_MAPPING_LENGHT];


BUTTON_MAPPING create_button_mapping(void) {
    BUTTON_MAPPING button_mapping = {};
    for (size_t i = 0; i < BUTTON_MAPPING_LENGHT; i++) {button_mapping[i] = dummy_function;}

    return (*button_mapping);
}


void process_user_input(BUTTON_MAPPING button_mapping) {
    
    char user_key;

    if (!kbhit()) {return;}

    user_key = getch();

    if (user_key == ESCAPE_VALUE || user_key == ESCAPE_VALUE_NUM_PAD) {user_key = getch();}

    
    button_mapping[user_key]();
    


}



int main(void) {



    
    //for (size_t i = 0; i < BUTTON_MAPPING_LENGHT; i++) {printf("%d\n", button_mapping[i] == dummy_function);}
    //printf("%p\n%p\n", x, dummy_function);



    //process_user_input(button_mapping);
    return 0;
}