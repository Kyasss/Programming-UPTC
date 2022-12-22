#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funciones
void funtion_numRoman();
void funtion_primeFactors();
void funtion_deleteSpaces();
void funtion_numEgotistical();
void funtion_numMagical();
void funtion_dates();
void funtion_productPoint();
void funtion_multArryas();
void funtion_magicArray();

// Menús
void menuPrincipal();
void menu_numRoman();
void menu_primeFactors();
void menu_deleteSpaces();
void menu_numEgotistical();
void menu_numMagical();
void menu_dates();
void menu_productPoint();
void menu_multArryas();
void menu_magicArray();

int main() {
    menuPrincipal();
    return 0;
}

// Instancia de Funciones

// Instancia Menus
void menuPrincipal() {
    int bucleMenu;
    int optionMenu;

    while (bucleMenu) {
        printf("---> Menu Principal\n\n"
               "[1] Numero romano.\n"
               "[2] Factores primos.\n"
               "[3] Borrar espacios.\n"
               "[4] Numeros egolatras.\n"
               "[5] Numero magico.\n"
               "[6] Fechas.\n"
               "[7] Producto punto.\n"
               "[8] Multiplicacion de matrices.\n"
               "[9] Matriz magica.\n\n"
               "[0] Salir.\n\n"
               "Digite una opcion...:");

        scanf("%i", &optionMenu);
        fflush(stdin);

        switch (optionMenu) {
            case 1:
                bucleMenu = 1;
                break;

            case 2:
                bucleMenu = 1;
                break;

            case 3:
                bucleMenu = 1;
                break;

            case 4:
                bucleMenu = 1;
                break;

            case 5:
                bucleMenu = 1;
                break;

            case 6:
                bucleMenu = 1;
                break;

            case 7:
                bucleMenu = 1;
                break;

            case 8:
                bucleMenu = 1;
                break;

            case 9:
                bucleMenu = 1;
                break;

            case 0:
                printf("Hasta pronto!");
                bucleMenu = 0;
                break;

            default:
                printf("Opcion invalida, intentelo de nuevo...\n\n");
                bucleMenu = 1;
                break;
        }
    }
}