/**
 * inicializalja a Board arrayt
 * @param BoardArray
 */
void initBoards(BOARD_ARRAY *BoardArray) {
    BoardArray->Boards = (Board *) calloc(0, sizeof(Board));
    BoardArray->size = 0;
}

/**
 * kiiratja a Board array tartalmat
 * @param BoardArray
 */
void printBoards(BOARD_ARRAY *BoardArray) {
    printf("*************************\n");
    printf("Boards count:\n");
    printf("*************************\n");

    for (int i = 0; i < BoardArray->size; i++) {
        printf("id: %d \n", BoardArray->boards[i].id);
        printf("id: %s \n", BoardArray->boards[i].name);
        printf("*************************\n");
    }

    printf("0. Back");
}

/**
 * beolvas es beszur egy uj Board-t a Board array-be.
 * @param a - Board array
 */
void readAndInsertBoard(BOARD_ARRAY *a) {
    Board p;
    printf("Kerem a szemely nevet (vezetek kereszt): \n");
    scanf("%s", &p.name);
    //"generalas" : vesszuk a kovetkezo szabad id-t
    p.id = a->size;
    //beszurjuk a felhasznalot
    insertBoard(a, p);
}

/**
 * Beszur egy Boardt a Board arraybe
 * @param a - Board array
 * @param Board -Board
 */
void insertBoard(BOARD_ARRAY *pArray, Board board) {
    pArray->size++;
    pArray->Boards = realloc(pArray->Boards, pArray->size * sizeof(board));
    pArray->Boards[pArray->size - 1] = Board;
}
