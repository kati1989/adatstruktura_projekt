#include <stdio.h>
#include "Person.h"
#include "Board.h"
#include <stdlib.h>

void felhasznaloMenu();

void tableMenu();

void kiirat_menu();

PERSON_ARRAY personArray;
BOARD_ARRAY boardArray;

int main() {
    printf("Hello, World!\n");
    PERSON person = (PERSON) {.id=2, .name="test"};
    initPersons(&personArray);
    initBoards(&boardArray);

    insertPerson(&personArray, person);
    person = (PERSON) {.id=3, .name="testr"};
    insertPerson(&personArray, person);

    int fomenu = -1;
    kiirat_menu();
    do {
        switch (fomenu) {
            case 1: {
                felhasznaloMenu();
                kiirat_menu();
                break;
            }
            case 2: {
                tableMenu();
                kiirat_menu();
                break;
            }
        }
        scanf("%d", &fomenu);
    } while (fomenu != 0);
    return 0;
}


void kiirat_tableMenu() {
    system("cls");
    printf("***************************************\n");
    printf("Tabla Menu :\n");
    printf("***************************************\n");
    printf("1. Letrehoz Tabla\n");
    printf("2. Kiirat Tablak\n");
    printf("3. Kiirat Tabla azonosito alapjan\n");
    printf("4. Letrehoz es hozzaad kartya tablahoz\n");
    printf("0. Kilepes\n");
    printf("***************************************\n");
}

void tableMenu() {
    int menu = -1;
    do {
        kiirat_tableMenu();
        switch (menu) {
            case 1:
                readAndInsertBoard(&boardArray);
                break;
            case 2:
                printBoards(&boardArray);
                break;
        }
        scanf("%d", &menu);
    } while (menu != 0);
}

void kiirat_felhasznaloMenu() {
    system("cls");
    printf("***************************************\n");
    printf("Felhasznalo Menu :\n");
    printf("***************************************\n");
    printf("1. Letrehoz Felhasznalo\n");
    printf("2. Kiirat Felhasznalok\n");
    printf("0. Kilepes\n");
    printf("***************************************\n");
}

void felhasznaloMenu() {
    int menu = -1;
    do {
        kiirat_felhasznaloMenu();
        switch (menu) {
            //felhasznalo beolvasasa es beszurasa
            case 1:
                readAndInsertPerson(&personArray);
                break;
                // osszes felhasznalo listazasa
            case 2:
                printPersons(&personArray);
                break;
        }
        scanf("%d", &menu);
    } while (menu != 0);
}

void kiirat_menu() {
    system("cls");
    printf("***************************************\n");
    printf("Fomenu :\n");
    printf("***************************************\n");
    printf("1. Muveletek Felhasznalokkal\n");
    printf("2. Muveletek Tablakkal\n");
    printf("0. Kilepes\n");
    printf("***************************************\n");
}