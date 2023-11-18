#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG(X, Y) printf("%s (%d): %s = %d. %s = %d\n", \
                 __FUNCTION__, __LINE__, #X, X, #Y, Y)
#define MAXSIZE 100
//#define _DEBUG_


char* addition(char* a, char* b);
char* division(char* sum, char* n);
int len(char* a) {
    int len;
    for (len = 0; a[len]; len++)
        ;
    return len;
}

int main(void) {
    char a[MAXSIZE] = { 0 }, b[MAXSIZE] = { 0 }, n[MAXSIZE] = { 0 };
    char* sum;
    char* reminder;

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", n);

    sum = addition(a, b);
    reminder = division(sum, n);
    printf("%s", reminder);

    return 0;
}

char* addition(char* a, char* b) {
    char* result;
    char rest = 0;
    int i, j;
    result = (char*)malloc(sizeof(char) * MAXSIZE);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, MAXSIZE);

    for (i = 0; a[i]; i++)
        ;
    for (j = 0; b[j]; j++)
        ;

    if (i > j) {
        for (i--, j--; j >= 0; i--, j--) {
            result[i] = (a[i] - '0' + b[j] - '0' + rest) % 10 + '0';
#ifdef _DEBUG_
            DEBUG(result[i], i);
#endif
            rest = (a[i] - '0' + b[j] - '0') / 10;
        }
        for (; i >= 0; i--) {
            result[i] = a[i] + '0';
#ifdef _DEBUG_
            DEBUG(result[i], i);
#endif
        }
    }
    else {
        for (i--, j--; i >= 0; i--, j--) {
            result[j] = (a[i] - '0' + b[j] - '0' + rest) % 10 + '0';
#ifdef _DEBUG_
            DEBUG(result[j], j);
#endif
            rest = (a[i] - '0' + b[j] - '0') / 10;
        }
        for (; j >= 0; j--) {
            result[j] = b[j] + '0';
#ifdef _DEBUG_
            DEBUG(result[j], j);
#endif
        }
    }
    return result;
}

char* division(char* sum, char* n) {
    char* result;
    result = (char*)malloc(sizeof(char) * MAXSIZE);
    if (result == NULL) {
        return NULL;
    }
    memset(result, '0', MAXSIZE);

    char* quotient;
    quotient = (char*)malloc(sizeof(char) * MAXSIZE);
    if (quotient == NULL) {
        return NULL;
    }
    memset(quotient, '0', MAXSIZE);

    char* temp;

    while (len(sum) >= len(temp = addition(quotient, n)) && strcmp(sum, temp) > 0) {
        free(temp);
        temp = quotient;
        quotient = addition(quotient, n);
        free(temp);
    }
    free(temp);

    int i;
    for (i = 0; sum[i]; i++)
        ;
    i--;
    while (strcmp(sum, (temp = addition(quotient, result)))) {
        free(temp);
        if (result[i] == '9') {
            result[i--] = '0';
            result[i]++;
        }
        else {
            result[i]++;
        }
    }
    free(temp);

    return result;
}