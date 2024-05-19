#include <windows.h>


// Función gotoxy para posicionar el cursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}