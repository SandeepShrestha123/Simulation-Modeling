#include<stdio.h>

int main()
{
    long int i, s, seed, x;
    int n;

    seed = 61;

    printf("How many random numbers to be generated:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        s = seed * seed;      // square
        x = (s / 10) % 100;   // extract middle 2 digits

        printf("x = %ld\n", x);

        seed = x;
    }

    return 0;
}