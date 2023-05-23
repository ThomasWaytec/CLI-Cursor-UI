/* Experiment with different ways to get input from user */


#include <stdio.h>
#include <conio.h>



int main(void) {

    char c;
    
    while (1) {

        c = getch();
        // parse arrows
        if (c == 0 || c == 224) { // if the first value is esc
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

        printf("%d, %c\n", c, c);
    }

    return 0;
}