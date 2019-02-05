#include <stdio.h>
#include <string.h>

#define N 10000000

static int cache [N];


int cycle_length(int n) 
{
    int res = 1;
    while(n != 1) {
        if(n < N && cache[n] > 0) return res+cache[n]- 1;
        if(n%2==1) n = 3*n+1;
        else n >>= 1;
        res++;
    }
    return res;
}

int max_cycle_length(int a, int b) {
    int res = 1;
    int i,c_len;
    if(b < a) {
        i = b; b = a; a = i;
    }
    for(i = a; i <= b; i++) {
        c_len = cycle_length(i);
        cache[i] = c_len;
        if(c_len > res) res = c_len;
    }
    return res;
}

int main(int argc, char *argv[]) 
{
    int i,j;
    cache[1] = 1;
    while(scanf("%d %d", &i, &j) == 2) {
        printf("%d %d %d\n", i, j, max_cycle_length(i, j));
    }
    return 0;
}

