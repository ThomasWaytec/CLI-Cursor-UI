/* 
Resources:

    GetConsoleScreenBufferInfo:
        https://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows

*/

#include <stdio.h>
#include <windows.h>

void print_terminal_dimensions(void) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    while (1) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        printf("columns: %d\n", columns);
        printf("rows: %d\n", rows);
        printf("\n");
        Sleep(3 * 1000);
    }

}



int main(void) {


    return 0;
}