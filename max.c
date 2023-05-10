#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long max1(long a, long b)
{
    return a * (a >= b) + b * (b > a);
}

long max2(long a, long b)
{
    return (a + b + labs(a - b)) >> 1;
}

long max3(long a, long b)
{
    if (a > b)
        return a;
    return b;
}

int main(void)
{
    long sum = 0;
    clock_t begin = clock();
    for (long i = 0; i < 100000; i++)
        for (long j = 0; j < 100000; j++)
            sum += max3(i,j);
    printf("%ld\n", sum);
    printf("%f\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
}
