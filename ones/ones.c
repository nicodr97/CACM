#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) 
{
    int n,found,c,a;

    while (scanf("%d",&n) == 1) {
        found = 0;
        a = n;
        c = 0;
        while (!found) {
            if (a == 0) {
                found = 1;
            }
            if (a == 1) {
                c++;
                found = 1;
            } else {
                if (a % 10 == 1) {
                    c++;
                    a = (int) a / 10;
                } else {
                    a += n;
                }
            }
        }
        printf("%d\n", c);
    }

    return 0;
}