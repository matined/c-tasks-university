// not sure if every task is done and only last 3 are entitled

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int mystrlen(const char *src) {
    int length = 0;
    while (src[length++] != '\0')
        ;
    return length - 1;
}

// bool isPalindrome(const char *src) {
//     int length = mystrlen(src);
//     for (int i = 0; i < length / 2; i++)
//         if (src[i] != src[length - i - 1]) return 0;
//     return 1;
// }

// void strrmidx(char *src, int i) {
//     while (src[i++] != '\0') src[i - 1] = src[i];
// }

// void strrmchr(char *src, char ch) {
//     char *pos;
//     pos = mystrchr(src, ch);
//     strrmidx(pos, 0);
// }

// void strrmchr_every(char *src, char ch) {
//     char *pos;
//     while (mystrchr(src, ch)) {
//         pos = mystrchr(src, ch);
//         strrmidx(pos, 0);
//     }
// }

// void remove_uppercase(const char *src) {
//     for (int i = 0; src[i] != '\0'; i++) {
//         if (src[i] >= 'A' && src[i] <= 'Z') {
//             strrmidx(src, i);
//             i--;
//         }
//     }
// }

// void srtrmsub(char *src, int start, int length) {
//     while (start < start + length) {
//         strrmidx(src, start);
//         start++;
//     }
// }

// int strrplcch(char *src, char toreplace, char replacewith) {
//     int count = 0;
//     while (*src != '\0') {
//         if (*src == toreplace) {
//             *src = replacewith;
//             count++;
//         }
//         src++;
//     }
//     return count;
// }

// void toUppercase(char *src) {
//     int diff = 'A' - 'a';
//     while (*src != '\0') {
//         if (*src >= 'a' && *src <= 'z') *src += diff;
//         src++;
//     }
// }

// task 16

void deleteChar(char *src, int pos) {
    for (int i = pos; src[i] != '\0'; i++) src[i] = src[i + 1];
}

void insertChar(char *src, char chr, int pos) {
    for (int i = mystrlen(src); i >= pos; i--) src[i + 1] = src[i];
    src[pos] = chr;
}

void strrplcsub(char *src, int start, int length, const char *replacement) {
    for (int i = 0; i < length; i++) deleteChar(src, start);
    for (int i = mystrlen(replacement) - 1; i >= 0; i--)
        insertChar(src, replacement[i], start);
}

// taks 17

int findString(const char *src, const char *toFind) {
    int lengthToFind = mystrlen(toFind), lengthSrc = mystrlen(src);
    for (int i = lengthSrc - 1; i >= lengthToFind - 1; i--) {
        bool isEqual = true;
        for (int j = 0; j < lengthToFind; j++) {
            if (src[i - j] != toFind[lengthToFind - j - 1]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) return i - lengthToFind + 1;
    }
    return -1;
}

int strrplcstr(char *src, const char *toreplace, const char *replacewith) {
    int numberOfReplacements = 0;
    int lengthToReplace = mystrlen(toreplace);
    while (findString(src, toreplace) != -1) {
        strrplcsub(src, findString(src, toreplace), lengthToReplace,
                   replacewith);
        numberOfReplacements++;
    }
    return numberOfReplacements;
}

// task 18   it gives some weird error

void replaceNumbers(char *src) {
    /**
     * @brief Replaces all numbers from 1 to 12 by theirs names.
     *
     * @param char A string to be modified
     */

    /////////////////////////////////////////////////////////////////////////
    /// todo: earn how to use this Doxygen documentation!
    /////////////////////////////////////////////////////////////////////////

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '1' && src[i + 1] == '0')
            strrplcsub(src, i, 2, "ten");
        else if (src[i] == '1' && src[i + 1] == '1')
            strrplcsub(src, i, 2, "eleven");
        else if (src[i] == '1' && src[i + 1] == '2')
            strrplcsub(src, i, 2, "twelve");
        else if (src[i] == '1')
            strrplcsub(src, i, 1, "one");
        else if (src[i] == '2')
            strrplcsub(src, i, 1, "two");
        else if (src[i] == '3')
            strrplcsub(src, i, 1, "three");
        else if (src[i] == '4')
            strrplcsub(src, i, 1, "four");
        else if (src[i] == '5')
            strrplcsub(src, i, 1, "five");
        else if (src[i] == '6')
            strrplcsub(src, i, 1, "six");
        else if (src[i] == '7')
            strrplcsub(src, i, 1, "seven");
        else if (src[i] == '8')
            strrplcsub(src, i, 1, "eight");
        else if (src[i] == '9')
            strrplcsub(src, i, 1, "nine");
    }
}

//////////////////////////////////////////////////
///////////////////// SIDE B /////////////////////
//////////////////////////////////////////////////

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(double *A, int size) {
    for (int i = 0; i < size - 1; i++) {
        int indexMin = i;
        for (int j = i + 1; j < size; j++)
            if (A[j] < A[indexMin]) indexMin = j;

        if (indexMin != i) swap(A + indexMin, A + i);
    }
}

void insertion_sort(double *A, int size) {
    for (int i = 1; i < size; i++) {
        double key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void bubble_sort(double *A, int size) {
    for (int i = 0; i <= size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (A[j] < A[j - 1]) swap(A + j, A + j - 1);
        }
    }
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
int main() {
    double A[5] = {2, 5, 7, 1, 6};
    selection_sort(A, 5);
    for (int i = 0; i < 5; i++) printf("%lf ", A[i]);
    return 0;
}
