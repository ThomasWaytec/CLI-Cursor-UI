
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

/* key = index in array; value = function pointer; */
/* to access a value, example: button_mapping['a'] */
void* button_mapping[127] = {};
void process_user_input() {
    
    char user_key;

    if (!kbhit()) {return;}

    user_key = getch();

    if (user_key == ESCAPE_VALUE || user_key == ESCAPE_VALUE_NUM_PAD) {user_key = getch();}

    
    return button_mapping[user_key]();
    


}
