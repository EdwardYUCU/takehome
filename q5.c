#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned long long n, k1, k2, answer;
    unsigned long long s1, s2;
    double sqrtN;

    scanf("%llu", &n);

    sqrtN = sqrt((double)n);
    s1 = (unsigned long long)sqrtN;
    s2 = s1 + 1;
    k1 = s1 * s1;
    k2 = s2 * s2;

    answer = ((k2 - n) > (n - k1)) ? k1 : k2;

    printf("%llu", answer);

    return 0;
}