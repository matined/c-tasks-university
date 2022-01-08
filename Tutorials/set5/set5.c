#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////
////////////////// TASK 1 //////////////////
typedef struct {
    int numerator;
    int denominator;
} rationalNumber;

// task 1a function: it returns a structure rationalNumber
rationalNumber createRationalNumber(int a, int b) {
    rationalNumber x;
    x.numerator = a;
    x.denominator = b;
    return x;
}

// task 1b function: it prints a rationalNumber as a fraction
void printRationalNumber(rationalNumber n) {
    printf("\n%d/%d", n.numerator, n.denominator);
}

// task 1c
void changeRationalNumber(rationalNumber *n) {
    printf("Enter a numerator and denominator: ");
    scanf("%d %d", &(n->numerator), &(n->denominator));
}

// task 1d
int GCD(int a, int b) {  // greatest common devisor
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

rationalNumber rationalSum(rationalNumber a, rationalNumber b) {
    rationalNumber new;
    new.denominator = a.denominator *b.denominator;
    new.numerator = a.numerator *b.denominator + b.numerator *a.denominator;
    int gcd = GCD(new.numerator, new.denominator);
    new.numerator /= gcd;
    new.denominator /= gcd;
    return new;
}

// task 1e
rationalNumber rationalDifference(rationalNumber a, rationalNumber b) {
    rationalNumber new;
    new.denominator = a.denominator *b.denominator;
    new.numerator = a.numerator *b.denominator - b.numerator *a.denominator;
    int gcd = GCD(new.numerator, new.denominator);
    new.numerator /= gcd;
    new.denominator /= gcd;
    return new;
}

// task 1f
rationalNumber rationalProduct(rationalNumber a, rationalNumber b) {
    rationalNumber new;
    new.denominator = a.denominator *b.denominator;
    new.numerator = a.numerator *b.numerator;
    int gcd = GCD(new.numerator, new.denominator);
    new.numerator /= gcd;
    new.denominator /= gcd;
    return new;
}

// task 1g
rationalNumber rationalQuotient(rationalNumber a, rationalNumber b) {
    rationalNumber new;
    new.denominator = a.denominator *b.numerator;
    new.numerator = a.numerator *b.denominator;
    int gcd = GCD(new.numerator, new.denominator);
    new.numerator /= gcd;
    new.denominator /= gcd;
    return new;
}

// task 1h
double valueOfRationalNumber(rationalNumber number) {
    return (double)number.numerator / number.denominator;
}

// task 1i
int compareRationalNumbers(rationalNumber a, rationalNumber b) {
    double aValue = valueOfRationalNumber(a), bValue = valueOfRationalNumber(b);
    if (aValue > bValue)
        return 1;
    else if (aValue < bValue)
        return -1;
    return 0;
}

////////////////////////////////////////////
////////////////// TASK 2 //////////////////
typedef struct {
    char firstName[10];
    char lastName[20];
    int semester;
} Student;

void printStudent(Student *s) {
    printf("\n%s %s %d", s->lastName, s->firstName, s->semester);
}

// function comparing students alphabetically (last name->first name->semester)
//  1 - the first greater
//  0 - equal
// -1 - the second greater
int compareStudents(Student a, Student b) {
    if (strcmp(a.lastName, b.lastName) == 1) return 1;
    if (strcmp(a.lastName, b.lastName) == -1) return -1;
    if (strcmp(a.firstName, b.firstName) == 1) return 1;
    if (strcmp(a.firstName, b.firstName) == -1) return -1;
    if (a.semester > b.semester) return 1;
    if (a.semester < b.semester) return -1;
    return 0;
}

// function swaping members of two Students
void swapStudents(Student *a, Student *b) {
    char firstNameTEMP[10], lastNameTEMP[20];
    int semesterTEMP;
    strcpy(firstNameTEMP, a->firstName);
    strcpy(lastNameTEMP, a->lastName);
    semesterTEMP = a->semester;

    strcpy(a->firstName, b->firstName);
    strcpy(a->lastName, b->lastName);
    a->semester = b->semester;

    strcpy(b->firstName, firstNameTEMP);
    strcpy(b->lastName, lastNameTEMP);
    b->semester = semesterTEMP;
}

// the part of the task to sort array of students - bubble sort
#define SIZEOFSSTUDENTSARRAY 5
void sortingStudents() {
    Student students[SIZEOFSSTUDENTSARRAY] = {{"Adam", "Nowak", 1},
                                              {"Ewa", "Kowalska", 3},
                                              {"Lukasz", "Wozniak", 2},
                                              {"Marek", "Kowalski", 5},
                                              {"Ewa", "Nowak", 3}};

    // bubble sort
    for (int i = 1; i < SIZEOFSSTUDENTSARRAY; i++) {
        for (int j = 1; j < SIZEOFSSTUDENTSARRAY - i + 1; j++) {
            if (compareStudents(students[j], students[j - 1]))
                swapStudents(students + j, students + j - 1);
        }
    }

    // show
    for (int i = 0; i < 5; i++) {
        printf("%s %s %d\n", students[i].lastName, students[i].firstName,
               students[i].semester);
    }
}
#undef SIZEOFSTUDENTSARRAY
////////////////////////////////////////////
////////////////// TASK 3 //////////////////
typedef struct {
    int meters;
    int centimeters;
} Length;

int compareLengths(Length a, Length b) {
    double difference = a.meters - b.meters + (double)a.centimeters / 100 -
                        (double)b.centimeters / 100;
    if (difference > 0) return 1;
    if (difference == 0) return 0;
    return -1;
}

Length addLengths(Length a, Length b) {
    Length new = {a.meters + b.meters, a.centimeters + b.centimeters};
    new.meters += new.centimeters / 100;
    new.centimeters %= 100;
    return new;
}

Length subtractLengths(Length a, Length b) {
    Length new = {a.meters - b.meters, a.centimeters - b.centimeters};
    new.meters += new.centimeters / 100;
    new.centimeters %= 100;
    return new;
}

////////////////////////////////////////////
////////////////// TASK 4 //////////////////
typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

void timeDiff(const Time a, const Time b, Time *toSave) {
    int aSeconds = a.seconds + a.minutes * 60 + a.hours * 3600,
        bSeconds = b.seconds + b.minutes * 60 + b.hours * 3600;
    int diff = abs(aSeconds - bSeconds);
    toSave->hours = diff / 3600;
    diff %= 3600;
    toSave->minutes = diff / 60;
    diff %= 60;
    toSave->seconds = diff;
}

////////////////////////////////////////////
////////////////////////////////////////////
int main() {
    sortingStudents();
    return 0;
}