
#include <stdio.h>
#include <conio.h>
#include <windows.h>


int main(void) {

    char c;
    
    size_t counter = 0;
    
    while (1) {

        counter++;

        Sleep(50);


        if (!kbhit()) {continue;}

        c = getch();

        if (c == 27) {break;} // ESC key

        if (c == 32) {printf("<SPACE>");}
        else if (c == 13) {printf("<ENTER>");}
        
        // parse arrows
        if (c == 0 || c == 224) { // if the first value is esc
            printf("<escape character>");

            switch(getch()) { // the real value
                case 72:
                    printf("Arrow Up\n");
                    // code for arrow up
                    break;
                case 80:
                    printf("Arrow Down\n");
                    // code for arrow down
                    break;
                case 75:
                    printf("Arrow Right\n");
                    // code for arrow right
                    break;
                case 77:
                    printf("Arrow Left\n");
                    // code for arrow left
                    break;
            }
        }

        else {printf("%d, %c\n", c, c);}
    }

    return 0;
}