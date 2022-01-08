#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// task 1
double ex1() {
    int size;
    double sum = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    double *array = (double *)calloc(size, sizeof(double));
    puts("Enter values:");
    for (int i = 0; i < size; i++) scanf("%lf", &array[i]);
    for (int i = 0; i < size; i++) sum += array[i];
    free(array);
    return sum;
}

// task 2
int *ex2(int num, int start, int step) {
    int *array = (int *)calloc(num, sizeof(int));
    for (int i = 0; i < num; i++) array[i] = start + i * step;
    return array;
}

// task 3
int *ex3(int number) {
    int size = 1;
    int *array = (int *)malloc(size * sizeof(int));
    array[0] = -1;
    while (number > 0) {
        size++;
        array = (int *)realloc(array, size * sizeof(int));
        for (int i = size - 1; i > 0; i--) array[i] = array[i - 1];
        array[0] = number % 10;
        number /= 10;
    }
    return array;
}

// task 4
char *ex4(const char *text) {
    char *newText = (char *)malloc(sizeof(char));
    *newText = '\0';
    int i = 0, size = 1;
    while (text[strlen(text) - i - 1] != '\0') {
        if (text[strlen(text) - i - 1] != ' ') {
            size++;
            newText = (char *)realloc(newText, size * sizeof(char));
            for (int j = size; j > 0; j--) newText[j] = newText[j - 1];
            newText[0] = text[strlen(text) - i - 1];
        }
        i++;
    }
    return newText;
}

// task 5
char *ex5(const char *a, const char *b) {
    char *newString = (char *)calloc(strlen(a) + strlen(b) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i < strlen(a); i++) newString[pos++] = a[i];
    for (int i = 0; i < strlen(b); i++) newString[pos++] = b[i];
    newString[pos] = '\0';
    return newString;
}

// task 6 - What do they mean by 'random'???
typedef struct {
    double Re, Im;
} CMPLX;

typedef struct {
    int numberOfElements;
    CMPLX *numbers;
} CMPLX_SET;

void create_random_set(CMPLX_SET *pcs, int num) {
    pcs->numberOfElements = num;
    pcs->numbers = (CMPLX *)calloc(num, sizeof(CMPLX));
    for (int i = 0; i < num; i++) {
        pcs->numbers[i].Re = rand() % 100 + 1;
        pcs->numbers[i].Im = rand() % 100 + 1;
    }
}

void delete_random_set(CMPLX_SET *pcs) { free(pcs->numbers); }

///////////////////////////////////////////////////////////////
int main() {
    srand(time(NULL));

    char *text = ex5("abc", "def");
    printf("%s", text);
    free(text);
    return 0;
}