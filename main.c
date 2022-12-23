#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>

// Funciones
int funtion_numRoman(char[]);
void funtion_primeFactors(long);
void funtion_deleteSpaces();
int funtion_numEgotistical(int);
int funtion_numMagical(int);
char *funtion_dates(char[]);
int funtion_productPoint(int[], int[]);
void funtion_multArryas(int,int,int,int);
void funtion_magicArray();
void funtion_continue();

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

void funtion_primeFactors(long numero){
    long numeroAux;
    long iterador = 0;

    numeroAux = numero;

    printf("\n----> %d = ",numeroAux);

    for (long i = 2; numero > 1 ; ++i) {
        if(iterador != 0){
            printf(" * ");
        }
        iterador = 0;
        if(numero % i == 0){
            while (numero %i == 0){
                iterador += 1;
                numero = numero/i;
            }
            if(iterador > 1){
                printf("%d^%d",i,iterador);
            }else if(iterador == 1){
                printf("%d",i);
            }
        }
    }
}

void funtion_deleteSpaces();

int funtion_numEgotistical(int numero){
    int suma = 0;


    int longitud = floor(log10(numero)) + 1;
    char numeroCadena[longitud + 1];

    sprintf(numeroCadena,"%d",numero);

    for (int i = 0; i < longitud; ++i) {
        int actual = numeroCadena[i] - '0';
        int potencia = pow(actual,longitud);
        suma += potencia;
    }

    if(suma == numero){
        return 1;
    }else {
        return 0;
    }
}

int funtion_numMagical(int numero){
    int numdes;
    int numAs;
    int longitud = floor(log10(numero)) + 1;
    char numeroCadena[longitud + 1];

    sprintf(numeroCadena,"%d",numero);

    for (int i = 0; i < longitud - 1; i++) {
        for (int j = i + 1; j < longitud; j++) {

            if (numeroCadena[i] < numeroCadena[j]) {
                int temporal = numeroCadena[i];
                numeroCadena[i] = numeroCadena[j];
                numeroCadena[j] = temporal;
            }
        }
    }

    numdes = atoi(numeroCadena);

    for (int i = 0; i < longitud - 1; i++) {
        for (int j = i + 1; j < longitud; j++) {

            if (numeroCadena[i] > numeroCadena[j]) {
                int temporal = numeroCadena[i];
                numeroCadena[i] = numeroCadena[j];
                numeroCadena[j] = temporal;
            }
        }
    }

    numAs = atoi(numeroCadena);

    if((numdes-numAs) == numero){
        return 1;
    }else{
        return 0;
    }

}

char *funtion_dates(char date[10]) {
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

        if (dayMax > 0) {
            if (day > dayMax) {
                printf("Ese mes no tiene tantos dias...\n\n");
            } else {
                printf("Su fecha es: %2i de %s de %i\n", day, months[month - 1], year);
            }
        } else {
            printf("Mes incorrecto...\n\n");
        }
    } else {
        printf("Formato de fecha incorrecto...\n\n");
    }
    return *dateFinal;
}

int funtion_productPoint(int matrizA[], int matrizB[]) {
    int sizeTotal = 0;
    int sizeMatrizA = sizeof(*matrizA);
    for (int i = 0; i < sizeMatrizA; ++i) {
        sizeTotal += matrizA[i] * matrizB[i];
    }
    return sizeTotal;
}

void funtion_multArryas(int fm1, int cm1,int fm2,int cm2){
    int m1[fm1][cm1];
    int m2[fm2][cm2];
    int m3[fm1][cm2];


    if(cm1 == fm2){
        for (int i = 0; i < fm1 ; ++i) {
            for (int j = 0; j < cm1; ++j) {
                m1[i][j] = rand() % 9 + 1;
            }
        }
        for (int i = 0; i < fm2 ; ++i) {
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
        for (int i = 0; i < fm1 ; ++i) {
            printf("  [");
            for (int j = 0; j < cm1; ++j) {
                printf(" %d ",m1[i][j]);
            }
            printf("]\n");
        }
        printf("\nSegunda matriz:\n\n");
        for (int i = 0; i < fm2 ; ++i) {
            printf("  [");
            for (int j = 0; j < cm2; ++j) {
                printf(" %d ",m2[i][j]);
            }
            printf("]\n");
        }
        printf("\nResultado:\n\n");
        for (int i = 0; i < fm1; ++i) {
            printf("  [");
            for (int j = 0; j < cm2; ++j) {
                if(m3[i][j] < 100){
                    printf("  %d ",m3[i][j]);
                }else{
                    printf(" %d ",m3[i][j]);
                }
            }
            printf("]\n");
        }
        printf("\n");
    } else{
        printf("\n----> Las matrices no son multiplicables\n");
    }
}

void funtion_multArryas();

void funtion_continue(){
    printf("\nPresiona enter para continuar.....:");

    char cad;
    cad = (char)getch();

    printf("\n");
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

    funtion_continue();
}

void menu_primeFactors(){
    long numero;

    printf("\n-->Descomponer un numero por factores primos<---\n\n");

    printf("Ingrese el numero (no mayor a 2147483646)...: ");
    scanf("%d",&numero);

    funtion_primeFactors(numero);

    funtion_continue();
}

void menu_deleteSpaces() {

}

void menu_numEgotistical(){
    int numero;

    printf("\n-->Determinar si un numero es egolatra<---\n");

    printf("\nDigite el numero.....: ");
    scanf("%d",&numero);
    fflush(stdin);

    if(funtion_numEgotistical(numero) == 1){
        printf("\n-----> %d es un numero egolatra\n", numero);
    }else {
        printf("\n-----> %d no es un numero egolatra\n", numero);
    }

    funtion_continue();
}

void menu_numMagical(){
    int numero;

    printf("\n-->Determinar si un numero es magico<---\n");

    printf("\nDigite el numero.....: ");
    scanf("%d",&numero);

    if(funtion_numMagical(numero) == 1){
        printf("\n-----> %d es un numero magico\n", numero);
    }else {
        printf("\n-----> %d no es un numero magico\n", numero);
    }

    funtion_continue();
}

void menu_dates() {
    char date[10];

    printf("---> Fechas\n"
           "- Ingrese una fecha con el formato [dd/mm/yyyy]");

    scanf("%s", date);
    funtion_dates(date);
    funtion_continue();
}

void menu_productPoint() {
    int sizeA, sizeB;

    printf("---> Producto punto\n"
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

        printf("El producto punto de ambas matrices es: %d \n", funtion_productPoint(matrizA, matrizB));
    } else {
        printf("Ambas matrices deben ser iguales...\n");
    }
    funtion_continue();
}

void menu_multArryas(){
    int fm1,cm1,fm2,cm2;

    printf("\n----->Multiplicar matrices<-----\n\n");

    printf("Ingrese el numero de filas de la primera matriz........: ");
    scanf("%d",&fm1);
    printf("\n");
    printf("Ingrese el numero de columnas de la primera matriz.....: ");
    scanf("%d",&cm1);
    printf("\n");
    printf("Ingrese el numero de filas de la segunda matriz........: ");
    scanf("%d",&fm2);
    printf("\n");
    printf("Ingrese el numero de columnas de la segunda matriz.....: ");
    scanf("%d",&cm2);

    funtion_multArryas(fm1,cm1,fm2,cm2);

    funtion_continue();
}

void menu_magicArray() {

}