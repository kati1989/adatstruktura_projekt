/**
 * inicializalja a person arrayt
 * @param personArray
 */
void initPersons(PERSON_ARRAY *personArray) {
    personArray->persons = (PERSON *) calloc(0, sizeof(PERSON));
    personArray->size = 0;
}

/**
 * kiiratja a person array tartalmat
 * @param personArray
 */
void printPersons(PERSON_ARRAY *personArray) {
    printf("*************************\n");
    printf("Persons count:\n");
    printf("*************************\n");

    for (int i = 0; i < personArray->size; i++) {
        printf("id: %d \n", personArray->persons[i].id);
        printf("id: %s \n", personArray->persons[i].name);
        printf("*************************\n");
    }

    printf("0. Back");
}

/**
 * beolvas es beszur egy uj person-t a person array-be.
 * @param a - person array
 */
void readAndInsertPerson(PERSON_ARRAY *a) {
    PERSON p;
    printf("Kerem a szemely nevet (vezetek kereszt): \n");
    scanf("%s", &p.name);
    //"generalas" : vesszuk a kovetkezo szabad id-t
    p.id = a->size;
    //beszurjuk a felhasznalot
    insertPerson(a, p);
}

/**
 * Beszur egy persont a person arraybe
 * @param a - person array
 * @param person -person
 */
void insertPerson(PERSON_ARRAY *pArray, PERSON person) {
    pArray->size++;
    pArray->persons = realloc(pArray->persons, pArray->size * sizeof(PERSON));
    pArray->persons[pArray->size - 1] = person;
}