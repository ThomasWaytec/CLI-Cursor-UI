#include <windows.h>

int main(void) {
    void* std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD top_left = {0, 0};
    SetConsoleCursorPosition(std_handle, top_left);
    return 0;
}