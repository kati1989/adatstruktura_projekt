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
} CARD;


typedef struct CardArray {
    CARD *cards;
    size_t size;
} CARD_ARRAY;

/**
 * inicializalja a Card arrayt
 * @param CardArray
 */
void initCards(CARD_ARRAY *CardArray) {
    CardArray->cards = (CARD *) calloc(0, sizeof(CARD));
    CardArray->size = 0;
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
    printf("Itt");
    pArray->size++;
    pArray->cards = realloc(pArray->cards, pArray->size * sizeof(CARD));


    pArray->cards[pArray->size - 1] = card;
    printf("Amott");

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
    scanf("%s", &p.personId);
    //"generalas" : vesszuk a kovetkezo szabad id-t
    p.id = a->size;
    p.status = TODO;
    //beszurjuk a kartyat
    insertCard(a, p);
    printf("Kartya beszurva!");
    return p.id;
}