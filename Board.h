
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
void initBoards(BOARD_ARRAY *BoardArray);

void printBoards(BOARD_ARRAY *BoardArray);

void readAndInsertBoard(BOARD_ARRAY *a);

void insertBoard(BOARD_ARRAY *pArray, BOARD board);