#include <cstdio>
#include <cmath>
#include <tuple>
#include <iostream>
#include <cstring>

using namespace std;

tuple <int,int> primes_exp[31];

int* prime_factorization(long x)
{
    long i;     /* counter */
    long c;     /* remaining product to factor */
    int n = 0;  /* number of primes */
    static int primes[32];

    c = x;
    while ((c % 2) == 0) {
        //printf("%ld\n",2);
        primes[n++] = 2;
        c = c / 2;
    }

    i = 3;
    while (i <= (sqrt(c)+1)) {
        if ((c % i) == 0) {
            //printf("%ld\n",i);
            primes[n++] = i;
            c = c / i;
        } else {
            i = i + 2;
        }
    }

    if (c > 1) {
        //printf("%ld\n",c);
        primes[n++] = c;
    }

    primes[31] = n;
    return primes;
}


int main(int argc, char *argv[]) 
{
    int primes[32],a,b;
    while (scanf( "%d %d", &a, &b ) == 2) {
        if (b == 0) {
            printf("%d does not divide %d!\n", b, a);
        } else if (b == 1) {
            printf("%d divides %d!\n", b, a);
        } else if (a == 0 || a == 1) {
            printf("%d does not divide %d!\n", b, a);
        } else if (b <= a) {
            printf("%d divides %d!\n", b, a);
        } else {
            memcpy(primes, prime_factorization(b), sizeof(primes));
            int len = primes[31];
            int i,j,nprimes,divides;
            j = 0;
            nprimes = 1;
            primes_exp[0] = make_tuple(primes[0],1);
            divides = 1;

            for (i = 1; i < len; i++) {
                if (primes[i] == get<0>(primes_exp[j])) {
                    get<1>(primes_exp[j]) = get<1>(primes_exp[j]) + 1;
                } else {
                    primes_exp[++j] = make_tuple(primes[i],1);
                    nprimes++;
                }
            }

            for (i = 0; i < nprimes; i++) {
                int p = get<0>(primes_exp[i]);
                int e = get<1>(primes_exp[i]);
                int x = p;
                int c = 0;
                while (x <= a && c < e) {
                    int y = x;
                    while (y % p == 0) {
                        c++;
                        y = y / p;
                    }
                    x+=p;
                }
                if (c < e) {
                    printf("%d does not divide %d!\n", b, a);
                    divides = 0;
                    i = nprimes;
                } 
            }

            if (divides) printf("%d divides %d!\n", b, a);
        }

    

    }
    return 0;
    
}