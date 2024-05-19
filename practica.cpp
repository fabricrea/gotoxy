#include <iostream>
#include <windows.h>
#include <cctype>

using namespace std;

// Función gotoxy para posicionar el cursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para cambiar el color del texto y del fondo
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Función para dibujar un cuadro
void dibujarCuadro(int x1, int y1, int x2, int y2) {
    // Esquinas del cuadro
    gotoxy(x1, y1); cout << char(187); // Esquina superior izquierda
    gotoxy(x2, y1); cout << char(191); // Esquina superior derecha
    gotoxy(x1, y2); cout << char(192); // Esquina inferior izquierda
    gotoxy(x2, y2); cout << char(188); // Esquina inferior derecha

    // Líneas horizontales
    for (int i = x1 + 1; i < x2; ++i) {
        gotoxy(i, y1); cout << char(196); // Línea horizontal superior
        gotoxy(i, y2); cout << char(196); // Línea horizontal inferior
    }

    // Líneas verticales
    for (int i = y1 + 1; i < y2; ++i) {
        gotoxy(x1, i); cout << char(179); // Línea vertical izquierda
        gotoxy(x2, i); cout << char(179); // Línea vertical derecha
    }
}
// Función para llenar la matriz
char** llenarMatriz(int &filas, int &columnas) {
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }

    cout << "Ingrese los caracteres para la matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    return matriz;
}

// Función para mostrar la matriz
void mostrarMatriz(char** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }
}

// Función para convertir la matriz a mayúsculas
void matrizMayuscula(char** matriz, int filas, int columnas, char** &matriz2) {
    matriz2 = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz2[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz2[i][j] = toupper(matriz[i][j]);
        }
    }
    mostrarMatriz(matriz2, filas, columnas);
}

// Función para convertir la matriz a minúsculas
void matrizMinuscula(char** matriz, int filas, int columnas, char** &matriz2) {
    matriz2 = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz2[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz2[i][j] = tolower(matriz[i][j]);
        }
    }
    mostrarMatriz(matriz2, filas, columnas);
}

// Función para contar la cantidad de veces que un carácter aparece en la matriz
void contarCaracteres(char** matriz, int filas, int columnas) {
    char caracter;
    cout << "Ingrese el carácter a buscar: ";
    cin >> caracter;

    int contador = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == caracter) {
                contador++;
            }
        }
    }

    if (contador > 0) {
        cout << "El carácter '" << caracter << "' aparece " << contador << " veces en la matriz.\n";
    } else {
        cout << "El carácter '" << caracter << "' no se encontró en la matriz.\n";
    }
}

void menu() {
    int opc, filas, columnas;
    bool salir = false;
    char **matriz = nullptr, **matriz2 = nullptr;

    // Cambiar el color de fondo a gris y el texto a rojo
    system("color 70");  // Fondo gris (7), texto negro (0)

    do {
        system("cls");
        setColor(4, 7);  // Texto rojo (4), fondo gris (7)
        dibujarCuadro(30, 1, 80, 5);
        gotoxy(45, 3);
        cout << " MENU DEL PROGRAMA " << endl;
        gotoxy(10, 4);

        setColor(4, 7);  // Texto rojo (4), fondo gris (7)
        dibujarCuadro(20, 6, 90, 8);
        gotoxy(30, 7);
        cout << "1. LLENAR MATRIZ CON CARACTERES" << endl;
        dibujarCuadro(20, 8, 90, 10);
        gotoxy(30, 9);	
        cout << "2. MOSTRAR LA MATRIZ" << endl;
        dibujarCuadro(20, 10, 90, 12);
        gotoxy(30, 11);
        cout << "3. PASAR MAYUSCULAS TODOS LOS DATOS" << endl;
        dibujarCuadro(20, 12, 90, 14);
        gotoxy(30, 13);
        cout << "4. PASAR A MINUSCULA TODOS LOS DATOS" << endl;
        dibujarCuadro(10, 14, 100, 16);
        gotoxy(20, 15);
        cout << "5. CONTAR LA CANTIDAD DE VECES EN QUE SE ENCUENTRA UN CARACTER EN LA MATRIZ" << endl;
        dibujarCuadro(20, 16, 90, 18);
        gotoxy(30, 17);
        cout << "6. Salir\n" << endl;

        gotoxy(40, 20);
        cout << "Ingresar una opcion: ";
        cin >> opc;
        cout << "\n";
        if ((opc < 1) || (opc > 6)) {
            cout << "Ingrese una opcion valida" << endl;
            system("pause");
        }
        switch (opc) {
            case 1: {
                matriz = llenarMatriz(filas, columnas);
                system("pause");
            }
            break;
            case 2: {
                mostrarMatriz(matriz, filas, columnas);
                system("pause");
            }
            break;
            case 3: {
                matrizMayuscula(matriz, filas, columnas, matriz2);
                system("pause");
            }
            break;
            case 4: {
                matrizMinuscula(matriz, filas, columnas, matriz2);
                system("pause");
            }
            break;
            case 5: {
                contarCaracteres(matriz, filas, columnas);
                system("pause");
            }
            break;
            case 6: {
                salir = true;
            }
            break;
        }
    } while (!salir);

    // Liberar memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
        delete[] matriz2[i];
    }
    delete[] matriz;
    delete[] matriz2;
}

int main() {
	system("chcp 437 > nul");
    setlocale(LC_CTYPE, "Spanish");
    menu();
    cout << "\n";
    system("pause");
    return 0;
}