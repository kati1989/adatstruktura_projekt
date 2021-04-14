
#include "Card.h"

typedef struct Board {
    /**
     * tabla azonosito
     */
    int id;
    /**
     * tabla neve
     */
    char name[100];
    /**
     * tabla kartyainak azonositoi
     */
    int cards[100];
    /**
     * tablahoz tartozo szemelyek azonositoi
     */
    int personIds[20];
    /**
     * kartyak szama
     */
    int cards_count;
    /**
     * szemelyek szama
     */
    int person_count;
} BOARD;

typedef struct BoardArray {
    BOARD *boards;
    size_t size;
} BOARD_ARRAY;

/**
 * inicializalja a Board arrayt
 * @param BoardArray
 */
void initBoards(BOARD_ARRAY *BoardArray) {
    BoardArray->boards = (BOARD *) calloc(0, sizeof(BOARD));
    BoardArray->size = 0;
}

/**
 * kiiratja a Board array tartalmat
 * @param BoardArray
 */
void printBoards(BOARD_ARRAY *boardArray) {
    printf("*************************\n");
    printf("Boards count:\n");
    printf("*************************\n");

    for (int i = 0; i < boardArray->size; i++) {
        printf("id: %d \n", boardArray->boards[i].id);
        printf("name: %s \n", boardArray->boards[i].name);
        printf("*************************\n");
    }

    printf("0. Back");
}

void printBoardById(int id, BOARD_ARRAY *boardArray, CARD_ARRAY *cardArray) {
    for (int i = 0; i < boardArray->size; i++) {
        if (boardArray->boards->id == id) {
            printf("*************************\n");
            printf("Board:\n");
            printf("*************************\n");
            printf("id: %d \n", boardArray->boards[i].id);
            printf("name: %s \n", boardArray->boards[i].name);
            printf("*************************\n");
            printf("Cards of Board:\n");
            printf("*************************\n");
            printf("%d",boardArray->boards[i].cards_count);
            for (int j = 0; j < boardArray->boards[i].cards_count; j++) {
                printCardById(boardArray->boards[j].cards[j], cardArray);
            }
            break;
        }
    }
}

/**
 * Beszur egy Boardt a Board arraybe
 * @param a - Board array
 * @param Board -Board
 */
void insertBoard(BOARD_ARRAY *pArray, BOARD board) {
    //"generalas" : vesszuk a kovetkezo szabad id-t
    board.id = pArray->size;
    board.cards_count = 0;
    board.person_count = 0;
    pArray->size++;
    pArray->boards = realloc(pArray->boards, pArray->size * sizeof(board));
    pArray->boards[pArray->size - 1] = board;
}

/**
 * beolvas es beszur egy uj Board-t a Board array-be.
 * @param a - Board array
 */
void readAndInsertBoard(BOARD_ARRAY *a) {
    BOARD p;
    printf("Kerem a tabla nevet: \n");
    scanf("%s", &p.name);
    //beszurjuk a felhasznalot
    insertBoard(a, p);
}

/**
 * Beolvas es hozzaad egy kartyat egy tablahoz.
 * @param boardArray
 * @param cardArray
 */
void readAndInsertCardToBoard(BOARD_ARRAY *boardArray, CARD_ARRAY *cardArray) {
    int boardId;
    printf("Kerem a tabla azonositojat: \n");
    scanf("%s", &boardId);

    int cardId = readAndInsertCard(cardArray);

    for (int i = 0; i < boardArray->size; i++) {
        if (boardArray->boards[i].id == boardId) {
            BOARD b ;
            b.id = &boardArray->boards[i].id;
            b.cards[b.cards_count] = cardId;
            b.cards_count++;
            boardArray->boards[i] = b;
        }
    }
}
