#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i, j, run = 10;
    float x, iat, st, awt, pcu, wt = 0, it = 0;
    float mean = 10.0, sd = 1.5, mue = 9.5, sigma = 1.0;
    float sb = 0.0, se = 0.0, cit = 0, cat = 0, cwt = 0;

    /* Header - widths match the data format %7.2f */
    printf("%-7s %-7s %-7s %-7s %-7s %-7s %-7s", "IAT", "CAT", "SB", "ST", "SE", "CWT", "CIT");
    printf("\n-------------------------------------------------------");

    for (j = 1; j <= run; ++j)
    {
        float sum = 0;

        /* Generate inter-arrival time using CLT approximation */
        for (i = 1; i <= 12; ++i)
        {
            x = (float)rand() / RAND_MAX;
            sum = sum + x;
        }
        iat = mean + sd * (sum - 6.0);
        cat = cat + iat;

        if (cat <= se)
        {
            sb  = se;
            wt  = se - cat;
            cwt = cwt + wt;
        }
        else
        {
            sb  = cat;
            it  = sb - se;
            cit = cit + it;
        }

        /* Generate service time using CLT approximation */
        sum = 0;
        for (i = 1; i <= 12; ++i)
        {
            x = (float)rand() / RAND_MAX;
            sum = sum + x;
        }
        st = mue + sigma * (sum - 6.0);
        se = sb + st;

        printf("\n%-7.2f %-7.2f %-7.2f %-7.2f %-7.2f %-7.2f %-7.2f",
               iat, cat, sb, st, se, cwt, cit);
    }  /* <-- end of for loop (was misplaced before) */

    printf("\n-------------------------------------------------------");

    awt = cwt / run;
    pcu = ((cat - cit) * 100.0) / cat;

    printf("\nAverage waiting time          = %6.2f", awt);
    printf("\nPercentage capacity utilization = %6.2f%%\n", pcu);

    return 0;
}