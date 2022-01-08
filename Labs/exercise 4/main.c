#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { AVAILABLE = 1, BORROWED = 0 } Status;

typedef struct {
    char title[80];
    int year;
    Status status;

} Book;

void printBook(Book *b) {
    printf("%s %d %d", b->title, b->year,
           b->status == 1 ? "available" : "borrowed");
}

void readBook(Book *b) {
    printf("Enter a title, year and status: ");
    scanf("%s %d %d", &b->title, &b->year, &b->status);
}
void copyBook(Book *dest, const Book *source) {
    strcpy(dest->title, source->title);
    dest->year = source->year;
    dest->status = source->status;
}
int compareBooks(Book *a, Book *b) { return }
// void sortBooks();

int main() {
    puts("**************** Part 1 ****************");
    /*
    Book a;
    //Test readBook, printBook on variable a

    */

    puts("\n**************** Part 2 ****************");
    /*
    Book b;
    puts("Copy Book (a to b)");
    //Test function copyBook using a and b, and use printBook to demonstrate the
    result

    */

    puts("\n**************** Part 3 ****************");
    /*
    //Read new data into b

    puts("\nComparing Books:");
    //Print both books and then the result of comparison between: a and b, b and
    a, b and b

    */

    puts("\n**************** Part 4 ****************");
    /*
    Book list[] = {
                    { "The Lord of the Rings", 1955, 1 },
                    { "Tristes Tropiques", 1955, 1 },
                    { "The Great Gatsby", 1925, 1 },
                    { "Waiting for Godot", 1952, 0 },
                    { "Midnight's Children", 1981, 0 },
                    { "1984", 1949, 0 },
                    { "For Whom the Bell Tolls", 1940,1 },
                    { "Il nome della rosa", 1981, 0 }
            };
    int const size = sizeof(list) / sizeof(Book);
    puts("Unsorted list:");
    //Print the array list

    //Sort it using sortBooks

    puts("\nSorted list:");
    //Print the array again

    */

    return 0;
}