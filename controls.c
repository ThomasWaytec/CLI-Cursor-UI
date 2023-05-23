/* Experiment with different ways to get input from user */

/*
resources:
    ReadConsoleInput:
        https://learn.microsoft.com/en-us/windows/console/reading-input-buffer-events
        https://stackoverflow.com/questions/46658472/non-blocking-readconsoleinput

    getch:
        https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
        https://stackoverflow.com/questions/10463201/getch-and-arrow-codes
        https://stackoverflow.com/questions/11472043/non-blocking-getch
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>


int main(void) {

    char c;
    
    while (1) {

        printf("Processing...\n");
        if (!kbhit()) {continue;}

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