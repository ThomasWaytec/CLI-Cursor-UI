#include <windows.h>

int main(void) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;

        while (1) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        printf("columns: %d\n", columns);
        printf("rows: %d\n", rows);
        }
    return 0;
}