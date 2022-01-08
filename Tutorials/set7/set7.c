#include <stdio.h>
#include <stdlib.h>

// defining the list's structs
typedef struct _LE {
    int number;
    struct _LE *next;
} ListElement;

typedef struct _List {
    ListElement *first, *current;
} List;

// task 1
ListElement *createNewListElement(int value) {
    ListElement *el = (ListElement *)malloc(sizeof(ListElement));
    el->number = value;
    el->next = NULL;
}

// task 2
void printElementOfList(const List l, int num) {
    ListElement *element = l.first;
    for (int i = 0; i < num; i++) element = element->next;
    printf("%d\n", element->number);
}

// task 3
void insertBeginnig(List *l, ListElement *newL) {
    newL->next = l->first;
    l->first = newL;
    l->current = l->first;
}

// task 4
void destroyList(List *l) {
    ListElement *element = l->first;
    ListElement *nextElement = element->next;
    while (nextElement != NULL) {
        free(element);
        element = nextElement;
        nextElement = element->next;
    }
}

// task 5
void printAllElementsAfterCurrent(const List l) {
    ListElement *element = l.current;
    while (element != NULL) {
        printf("%d\n", element->number);
        element = element->next;
    }
}

// task 6
void printAllElements(const List list) {
    ListElement *element = list.first;
    while (element != NULL) {
        printf("%d\n", element->number);
        element = element->next;
    }
}

// task 7
void insertEnding(List *list, ListElement *newL) {
    if (list->first == NULL) {
        list->first = newL;
        list->current = newL;
    } else {
        ListElement *element = list->current;
        while (element->next != NULL) element = element->next;
        element->next = newL;
        list->current = newL;
    }
}

int main() {
    List list;
    insertEnding(&list, createNewListElement(5));
    insertBeginnig(&list, createNewListElement(4));
    insertBeginnig(&list, createNewListElement(3));
    printAllElements(list);
    return 0;
}