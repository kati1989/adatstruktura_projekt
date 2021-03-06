#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Board.h"

void felhasznaloMenu();

void tableMenu();

void kiirat_menu();

PERSON_ARRAY personArray;
BOARD_ARRAY boardArray;
CARD_ARRAY cardArray;

int main() {
    printf("Hello, World!\n");
    PERSON person = (PERSON) {.id=0, .name="test"};
    initPersons(&personArray);
    initBoards(&boardArray);
    initCards(&cardArray);
// egy par kezdeti adat teszteles celjabol
    insertPerson(&personArray, person);
    person = (PERSON) {.id=1, .name="szemely1"};
    insertPerson(&personArray, person);

    BOARD board = (BOARD){.name="board1", .cards_count=2, .cards={0,1} };
    insertBoard(&boardArray,board);

    board = (BOARD){.name="board2" };
    insertBoard(&boardArray,board);

    CARD  card = (CARD){ .id=0, .taskName="name" , .personId=0 };
    insertCard(&cardArray,card);

    card = (CARD){.id=1, .taskName="name2", .personId=1};
    insertCard(&cardArray,card);

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
    printf("5. Hozzarendel felhasznalo tablahoz\n");
    printf("6. Hozzarendel felhasznalo kartyahoz\n");
    printf("7. Kartyan dolgozo felhasznalok listaja\n");
    printf("8. Kartya adatainak modositasa\n");
    printf("9. Kartya torlese tablabol\n");
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
            case 3: {
                int id;
                printf("Kerem a tabla id-jat:");
                scanf("%d", &id);
                printBoardById(id, &boardArray, &cardArray, &personArray);
            }
                break;
            case 4: {
                readAndInsertCardToBoard(&boardArray,&cardArray);
            }
            case 5: {
                insertPersonToBoard(&boardArray,&personArray);
            }
            case 6: {
                addPersonToCard(&personArray,&cardArray);
            }
            case 7: {
                printPersonsOnCard(&personArray,&cardArray);
            }
            case 8: {
                modifyCard(&cardArray);
            }
            case 9: {
                deleteCard(&cardArray);
            }
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