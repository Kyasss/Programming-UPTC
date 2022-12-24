#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>

// Variables para el uso del metodo de matrices magicas
#define nums 100
int matriz[nums][nums];

// Funciones complementarias
void consumirNuevaLinea();

void pressEnter();

// Funciones
int funtion_numRoman(char[]);

void funtion_primeFactors(long);

void funtion_deleteSpaces(char[], char []);

int funtion_numEgotistical(int);

int funtion_numMagical(int);

void funtion_dates(char[]);

int funtion_productPoint(int[], int[], int);

void funtion_multArryas(int, int, int, int);

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
int funtion_numRoman(char numRoman[10]) {
    int number[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int addition = 0;

    for (int i = 0; i < strlen(numRoman); ++i) {
        switch (numRoman[i]) {

            case 'M':
                number[i] = 1000;
                break;
            case 'D':
                number[i] = 500;
                break;
            case 'C':
                number[i] = 100;
                break;
            case 'L':
                number[i] = 50;
                break;
            case 'X':
                number[i] = 10;
                break;
            case 'V':
                number[i] = 5;
                break;
            case 'I':
                number[i] = 1;
                break;

            default:
                printf("\n Has introducido caracteres invalidos");
                number[i] = 0;
                break;
        }
    }
    for (int i = 0; i < strlen(numRoman); ++i) {
        if (number[i] >= number[i + 1]) {
            addition += number[i];
        } else {
            addition -= number[i];
        }
    }
    return addition;
}

void funtion_primeFactors(long number) {
    long numberAux;
    long iterator = 0;

    numberAux = number;
    printf("\n---> %d =", numberAux);

    for (long i = 2; number > 1; ++i) {
        if (iterator != 0) {
            printf(" * ");
        }
        iterator = 0;
        if (number % i == 0) {
            while (number % i == 0) {
                iterator += 1;
                number = number / i;
            }
            if (iterator > 1) {
                printf("%d^%d", i, iterator);
            } else if (iterator == 1) {
                printf("%d", i);
            }
        }
    }
}

void funtion_deleteSpaces(char string[], char stringWithoutSpaces[]) {
    int i = 0;
    int j = 0;

    while (string[i] != '\0') {
        if (string[i] != ' ') {
            stringWithoutSpaces[j] = string[i];
            j++;
        }
        i++;
    }
}

int funtion_numEgotistical(int number) {
    int adittion = 0;
    int size = floor(log10(number)) + 1;
    char numberString[size + 1];

    sprintf(numberString, "%d", number);

    for (int i = 0; i < size; ++i) {
        int now = numberString[i] - '0';
        int potency = pow(now, size);
        adittion += potency;
    }

    if (adittion == number) {
        return 1;
    } else {
        return 0;
    }
}

int funtion_numMagical(int number) {
    int numDes, numAs;
    int size = floor(log10(number)) + 1;
    char numberString[size + 1];

    sprintf(numberString, "%d", number);

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {

            if (numberString[i] < numberString[j]) {
                int temporal = numberString[i];
                numberString[i] = numberString[j];
                numberString[j] = temporal;
            }
        }
    }

    numDes = atoi(numberString);

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {

            if (numberString[i] > numberString[j]) {
                int temporal = numberString[i];
                numberString[i] = numberString[j];
                numberString[j] = temporal;
            }
        }
    }

    numAs = atoi(numberString);

    if ((numDes - numAs) == number) {
        return 1;
    } else {
        return 0;
    }
}

void funtion_dates(char date[10]) {
    char *months[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre",
                        "octubre", "noviembre", "diciembre"};
    char *dateFinal[200];
    int day, month, year, control;
    int counter = 0;
    int dayMax = 0;

    char *token;
    token = strtok(date, "/");
    while (token != NULL) {
        counter++;
        switch (counter) {
            case 1:
                control = day = atoi(token);
                break;

            case 2:
                control = month = atoi(token);
                break;

            case 3:
                control = year = atoi(token);
                break;
        }
        if (control == 0) break;
        token = strtok(NULL, "/");
    }

    if (control != 0 && counter == 3) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dayMax = 31;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                dayMax = 30;
                break;

            case 2:
                if (year % 4 == 0) dayMax = 29;
                else dayMax = 28;
                break;
        }

        if (year > 2022) {
            printf("Aun no estamos en ese anio...\n");
        } else {
            if (day > dayMax) {
                printf("Ese mes no tiene tantos dias...\n");
            } else {
                printf("Su fecha es: %2i de %s de %i\n", day, months[month - 1], year);
            }
        }
    } else {
        printf("Formato de fecha incorrecto...\n");
    }
}

int funtion_productPoint(int matrizA[], int matrizB[], int sizeMatriz) {
    int sizeTotal = 0;
    for (int i = 0; i < sizeMatriz; ++i) {
        sizeTotal += matrizA[i] * matrizB[i];
    }
    return sizeTotal;
}

void funtion_multArryas(int fm1, int cm1, int fm2, int cm2) {
    int m1[fm1][cm1];
    int m2[fm2][cm2];
    int m3[fm1][cm2];

    if (cm1 == fm2) {
        for (int i = 0; i < fm1; ++i) {
            for (int j = 0; j < cm1; ++j) {
                m1[i][j] = rand() % 9 + 1;
            }
        }
        for (int i = 0; i < fm2; ++i) {
            for (int j = 0; j < cm2; ++j) {
                m2[i][j] = rand() % 9 + 1;
            }
        }
        for (int i = 0; i < fm1; ++i) {
            for (int j = 0; j < cm2; ++j) {
                m3[i][j] = 0;
                for (int k = 0; k < cm1; ++k) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        printf("\nPrimera matriz:\n\n");
        for (int i = 0; i < fm1; ++i) {
            printf("  [");
            for (int j = 0; j < cm1; ++j) {
                printf(" %d ", m1[i][j]);
            }
            printf("]\n");
        }
        printf("\nSegunda matriz:\n\n");
        for (int i = 0; i < fm2; ++i) {
            printf("  [");
            for (int j = 0; j < cm2; ++j) {
                printf(" %d ", m2[i][j]);
            }
            printf("]\n");
        }
        printf("\nResultado:\n\n");
        for (int i = 0; i < fm1; ++i) {
            printf("  [");
            for (int j = 0; j < cm2; ++j) {
                if (m3[i][j] < 100) {
                    printf("  %d ", m3[i][j]);
                } else {
                    printf(" %d ", m3[i][j]);
                }
            }
            printf("]\n");
        }
        printf("\n");
    } else {
        printf("\n----> Las matrices no son multiplicables\n");
    }
}

void funtion_magicArray(int number) {
    if (number % 2 == 0) {
        printf("NULL\n");
        return;
    }

    int i = 1;
    int j = (1 + number) / 2;
    matriz[i][j] = 1;

    for (int value = 2; value <= number * number; ++value) {
        i -= 1;
        j += 1;
        if (i < 1 && j > number) {
            i += 2;
            j -= 1;
        } else {
            if (i < 1) {
                i = number;
            }
            if (j > number) {
                j = 1;
            }
        }
        if (matriz[i][j] == 0) {
            matriz[i][j] = value;
        } else {
            i += 2;
            j -= 1;
            matriz[i][j] = value;
        }
    }

    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= number; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

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
                menu_numRoman();
                bucleMenu = 1;
                break;

            case 2:
                menu_primeFactors();
                bucleMenu = 1;
                break;

            case 3:
                menu_deleteSpaces();
                bucleMenu = 1;
                break;

            case 4:
                menu_numEgotistical();
                bucleMenu = 1;
                break;

            case 5:
                menu_numMagical();
                bucleMenu = 1;
                break;

            case 6:
                menu_dates();
                bucleMenu = 1;
                break;

            case 7:
                menu_productPoint();
                bucleMenu = 1;
                break;

            case 8:
                menu_multArryas();
                bucleMenu = 1;
                break;

            case 9:
                menu_magicArray();
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

void menu_numRoman() {
    char numRoman[10];
    printf("---> Menu numero romano\n"
           "Ingrese un numero romano...");

    scanf("%s", numRoman);
    for (int i = 0; i < strlen(numRoman); ++i) {
        numRoman[i] = toupper(numRoman[i]);
    }

    printf("El valor [ %s ] en numeros decimales es: %d\n", numRoman, funtion_numRoman(numRoman));
    pressEnter();
}

void menu_primeFactors() {
    long number;

    printf("---> Menu factores primos\n"
           "Ingrese una numero...");
    scanf("%d", &number);

    funtion_primeFactors(number);
    pressEnter();
}

void menu_deleteSpaces() {
    char string[100];
    char stringWithoutSpaces[100];
    printf("---> Menu borrar espacios\n"
           "Ingrese una cadena de caracteres...");

    consumirNuevaLinea();
    fgets(string, 100, stdin);

    funtion_deleteSpaces(string, stringWithoutSpaces);
    printf("La cadena sin espacios es: %s", stringWithoutSpaces);
    pressEnter();
}

void menu_numEgotistical() {
    int number;

    printf("---> Menu numero egolatra\n"
           "Digite un numero...");
    scanf("%d", &number);
    fflush(stdin);

    if (funtion_numEgotistical(number) == 1) {
        printf("El numero %d es un numero egolatra", number);
    } else {
        printf("El numero %d NO es un numero egolatra", number);
    }
    pressEnter();
}

void menu_numMagical() {
    int number;

    printf("---> Menu numero magico\n"
           "Ingrese una cadena de caracteres...");
    scanf("%d", number);

    if (funtion_numMagical(number) == 1) {
        printf("El numero %d es un numero magico", number);
    } else {
        printf("El numero %d NO es un numero magico", number);
    }
    pressEnter();
}

void menu_dates() {
    char date[10];

    printf("---> Menu fechas\n"
           "- Ingrese una fecha con el formato [dd/mm/yyyy]");

    scanf("%s", date);
    fflush(stdin);

    funtion_dates(date);
    pressEnter();
}

void menu_productPoint() {
    int sizeA, sizeB;

    printf("---> Menu producto punto\n"
           "- Ingrese el tamanho del vector A:");
    scanf("%d", &sizeA);

    printf("- Ingrese el tamanho del vector B:");
    scanf("%d", &sizeB);

    if (sizeA == sizeB) {
        int matrizA[sizeA], matrizB[sizeB];

        for (int i = 0; i < sizeA; i++) {
            printf("A [%d] =", i + 1);
            scanf("%d", &matrizA[i]);
            fflush(stdin);
        }

        for (int j = 0; j < sizeB; j++) {
            printf("B [%d] =", j + 1);
            scanf("%d", &matrizB[j]);
            fflush(stdin);
        }

        printf("Producto punto: %d \n", funtion_productPoint(matrizA, matrizB, sizeA));
        pressEnter();
    } else {
        printf("Ambas matrices deben ser iguales...\n");
        pressEnter();
    }
}

void menu_multArryas() {
    int rows1, columns1, rows2, columns2;

    printf("---> Menu multiplicar matrices\n"
           "- Ingrese las filas de la primera matriz:");
    scanf("%d", &rows1);

    printf("- \nIngrese las columnas de la primera matriz:");
    scanf("%d", &columns1);

    printf("- \nIngrese las filas de la segunda matriz:");
    scanf("%d", &rows2);

    printf("- \nIngrese las columnas de la segunda matriz:");
    scanf("%d", &columns2);

    funtion_multArryas(rows1, columns1, rows2, columns2);
    pressEnter();
}

void menu_magicArray() {
    int matriz[nums][nums];
    int number;

    printf("---> Menu matriz magica\n"
           "- Ingrese el numero de elementos:");

    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= number; j++) {
            matriz[i][j] = 0;
        }
    }

    printf("\nLa funcion es: \n");
    funtion_magicArray(number);
    pressEnter();
}

// Funciones complementarias
void consumirNuevaLinea(void) {
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

void pressEnter() {
    printf("\nPresione enter para continuar...");
    char tecla = getch();
    if (tecla == ' ') {
        getch();
    }
}