#include "Person.h"

enum Status {
    TODO, DOING, DONE
};

typedef struct Card {
    /**
     * kartya egyedi azonositoja
     */
    int id;
    /**
     * kartya neve
     */
    char taskName[100];
    /**
     * kartya statusza
     */
    enum Status status;
    /**
     * szemely id ja
     */
    int personId;
    /**
     * regebbi szemelyek idjai
     */
    int pastWorkers[100];
    /**
     * regi dolgozok szama
     */
    int pastWorkers_count;
} CARD;


typedef struct CardArray {
    CARD *cards;
    size_t size;
} CARD_ARRAY;

/**
 * inicializalja a Card arrayt
 * @param CardArray
 */
void initCards(CARD_ARRAY *cardArray) {
    cardArray->cards = (CARD *) calloc(0, sizeof(CARD));
    cardArray->size = 0;
}

/**
 * kiiratja a Card array tartalmat
 * @param CardArray
 */
void printCards(CARD_ARRAY *CardArray) {
    printf("*************************\n");
    printf("Cards count:\n");
    printf("*************************\n");
    for (int i = 0; i < CardArray->size; i++) {
        printf("id: %d \n", CardArray->cards[i].id);
        printf("task name: %s \n", CardArray->cards[i].taskName);
        printf("person id: %s \n", CardArray->cards[i].personId);
        printf("*************************\n");
    }
    printf("0. Back");
}

void printCardById(int id, CARD_ARRAY *cardArray) {
    for (int i = 0; i < cardArray->size; i++) {
        if (cardArray->cards[i].id == id) {
            printf("*************************\n");
            printf("Card:\n");
            printf("*************************\n");
            printf("id: %d \n", cardArray->cards[i].id);
            printf("task name: %s \n", cardArray->cards[i].taskName);
            printf("person id: %s \n", cardArray->cards[i].personId);
            break;
        }
    }
}

/**
 * Beszur egy Cardt a Card arraybe
 * @param a - Card array
 * @param Card -Card
 */
void insertCard(CARD_ARRAY *pArray, CARD card) {
    pArray->size++;
    pArray->cards = realloc(pArray->cards, pArray->size * sizeof(CARD));
    pArray->cards[pArray->size - 1] = card;
}

/**
 * beolvas es beszur egy uj Card-t a Card array-be.
 * @param a - Card array
 */
int readAndInsertCard(CARD_ARRAY *a) {
    CARD p;
    printf("Kerem a kartya nevet: \n");
    scanf("%s", &p.taskName);
    printf("Kerem a felhasznalo azonositojat: \n");
    scanf("%d", &p.personId);
    //"generalas" : vesszuk a kovetkezo szabad id-t
    p.id = a->size;
    p.status = TODO;
    //beszurjuk a kartyat
    insertCard(a, p);
    printf("Kartya beszurva!");
    return p.id;
}

void addPersonToCard(PERSON_ARRAY *personArray, CARD_ARRAY *cardArray) {
    int personId, cardId;
    printf("Kerem a kartya azonositojat: \n");
    scanf("%d", cardId);
    printf("Kerem a felhasznalo azonositojat: \n");
    scanf("%d", &personId);
    for (int i = 0; i < cardArray->size; i++) {
        cardArray->cards[i].pastWorkers[cardArray->cards[i].pastWorkers_count] = cardArray->cards[i].personId;
        cardArray->cards[i].pastWorkers_count++;
        cardArray->cards[i].personId = personId;
    }
}

/**
 * Kartyan dolgozo szemelyek kiiratasa
 * @param cardArray
 * @param personArray
 */
void printPersonsOnCard(CARD_ARRAY *cardArray, PERSON_ARRAY *personArray) {
    int cardId;
    printf("Kerem a kartya azonositojat: \n");
    scanf("%d", cardId);

    for (int i = 0; i < cardArray->size; i++) {
        if (cardArray->cards[i].id == cardId) {

            printPersonById(cardArray->cards[i].personId, personArray);
            for (int j = 0; j < cardArray->cards[i].pastWorkers_count; j++) {
                printPersonById(cardArray->cards[i].pastWorkers, personArray);
            }
        }
    }
}

/**
 * Kartya adatainak modositasa
 * @param cardArray
 */
void modifyCard(CARD_ARRAY *cardArray) {
    int cardId, option = 0;
    printf("Kerem a kartya azonositojat: \n");
    scanf("%d", &cardId);
    printf("Kerem a modositando  tulajdonsagot: \n");
    printf("1. Kartya neve \n");
    printf("2. Status \n");
    printf("3. Szemely \n");
    scanf("%d", &option);

    for (int i = 0; i < cardArray->size; i++) {
        if (cardArray->cards[i].id == cardId) {

            switch (option) {
                case 1: {
                    printf("1. Kartya neve: ");
                    scanf("%s", &cardArray->cards[i].taskName);
                }
                    break;
                case 2: {
                    printf("2. status: (0-TODO 1-DOING 2-DONE)");
                    scanf("%d", &cardArray->cards[i].status);
                }
                    break;
                case 3: {
                    printf("3. personID: ");
                    scanf("%d", &cardArray->cards[i].personId);
                }
                    break;
            }
        }
    }
}

void deleteCard(CARD_ARRAY *cardArray) {
    int cardId;
    printf("Kerem a kartya azonositojat: \n");
    scanf("%d", &cardId);

    for (int i = 0; i < cardArray->size; i++) {
        if (cardArray->cards[i].id == cardId) {
            cardId = i;
            break;
        }
    }

    for (int i = cardId; i < cardArray->size - 1; i++) {
        cardArray->cards[i] = cardArray->cards[i + 1];
    }
    cardArray->size--;
}
