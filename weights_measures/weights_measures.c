#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define N 5608

static int index[N], W[N], C[N];



int compare(const void *v1, const void *v2) 
{
    int *i1 = (int *)v1;
    int *i2 = (int *)v2;

    if ( *i1 < *i2 )
        return -1;
    else if ( *i1 > *i2 )
        return 1;
    else
        return 0;
}

int compare2(const void *v1, const void *v2) 
{
    int *i1 = (int *)v1;
    int *i2 = (int *)v2;

    if ( C[*i1] < C[*i2] )
        return -1;
    else if ( C[*i1] > C[*i2] )
        return 1;
    else
        return 0;
}


int max(int a, int b) 
{
    if (a >= b) return a;
    else return b;
}

int main(int argc, char *argv[])
{
    int i,j,n;
    
    for (i=0; i < N; i++) C[i] = INT_MAX;
    for (i=0; i < N; i++) W[i] = INT_MAX;
    for (i=0; i < N; i++) index[i] = i;

    i=0;
    while (scanf("%d %d", &W[i], &C[i]) == 2) i++;

    qsort(index, N, sizeof(int), compare2);
    qsort(C, i, sizeof(int), compare);

    int temp[i];
    for (j = 0; j < i; j++) temp[j] = W[j];
    for (j = 0; j < i; j++) W[j] = temp[index[j]];

    int dp[i+1];
    for (j = 0; j <= i; j++) dp[j] = INT_MAX;
    dp[0] = 0;

    int max_l = 0;
    n=i;
    for (i = 0; i < n; i++) {
        for (j = max_l; j >= 0; j--) {
            int w = W[i] + dp[j];
            if (w <= C[i]) {
                if (w < dp[j+1]) {
                    dp[j+1] = w;
                    max_l = max(j+1, max_l);
                }
            }
        }
    }
    
    printf("%d\n", max_l);

    return 0;
}