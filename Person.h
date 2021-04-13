#include <stdlib.h>

typedef struct Person {
    /**
     * szemely azonositoja
     */
    int id;
    /**
     * szemely neve
     */
    char name[100];
} PERSON;

typedef struct PersonArray {
    PERSON *persons;
    size_t size;
} PERSON_ARRAY;

void initPersons(PERSON_ARRAY *personArray);

void insertPerson(PERSON_ARRAY *pArray, PERSON person);

void printPersons(PERSON_ARRAY *personArray);

void readAndInsertPerson(PERSON_ARRAY *a);