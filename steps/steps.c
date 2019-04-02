#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static int steps[92681]; 


int binSearch(int n) 
{
    int j = 92681;
    int i = 0;
    int m = 0;
    while (i <= j) {
        m = (i+j)/2;
        if (steps[m] == n || j == i) break;
        if (j-i == 1) {
            if (steps[j] > n) m = i;
            else m = j;
            break;
        }
        if (steps[m] < n) i = m;
        else j = m - 1;
    }

    return m;
}


int main(int argc, char *argv[])
{
    int num_cases,a,b,i,delta,count;
    scanf("%d", &num_cases);

    steps[0] = 0;
    steps[1] = 1;
    steps[2] = 2;
    steps[3] = 3;

    delta = 2;
    count = 2;

    for (i = 4; i < 92681; i++) {
        if (count == 0) {
            delta++;
            count = 2;
        }
        steps[i] = steps[i-1] + delta;
        count--;
    }


    while (--num_cases >= 0) {
        scanf("%d %d", &a, &b);
        int n = b - a;
        int number = binSearch(n);
        printf("%d\n", number);
    } 

    


    return 0;
}