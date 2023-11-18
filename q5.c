#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

char* addition(char* a, char* b);

int main(void) {
    char a[MAXSIZE] = { 0 }, b[MAXSIZE] = { 0 }, n[MAXSIZE] = { 0 };
    char* sum;

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", n);
    sum = addition(a, b);
    printf("%s", sum);

    return 0;
}

char* addition(char a[], char b[]) {
    char* result;
    char rest = 0;
    int i, j;
    result = (char*)malloc(sizeof(char) * MAXSIZE);
    memset(result, 0, MAXSIZE);
    for (i = 0; a[i]; i++)
        ;
    for (j = 0; b[j]; j++)
        ;

    if (i > j) {
        for (i--, j--; j >= 0; i--, j--) {
            result[i] = (a[i] + b[j] + rest) % 10;
            rest = (a[i] + b[j]) / (char)10;
        }
        for (; i >= 0; i--) {
            result[i] = a[i];
        }
    }
    else {
        for (i--, j--; i >= 0; i--, j--) {
            result[j] = (a[i] + b[j] + rest) % 10;
            rest = (char)((a[i] + b[j]) / 10);
        }
        for (; j >= 0; j--) {
            result[j] = b[j];
        }
    }
    return result;
}