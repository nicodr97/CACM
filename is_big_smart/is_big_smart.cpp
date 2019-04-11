#include <cstdio>
#include <algorithm>
#include <climits>

#define N 1000

using namespace std;


class Elephant 
{
public:
    int index;
    int w;
    int s;

    Elephant() {
        this->index = -1;
        this->w = INT_MAX;
        this->s = 0;
    }

    void setData(int i, int w, int s) 
    {
        this->index = i;
        this->w = w;
        this->s = s;
    }

    bool operator < ( Elephant & other )
    {
        // For sorting in ascending order of height
        if ( this->w < other.w ) return true;
        if ( this->w > other.w ) return false;

        // and descending order of weight when same height
        if ( this->s > other.s ) return true;
        if ( this->s < other.s ) return false;

        return false;
    }
};

bool comparatorFunction( Elephant e1, Elephant e2 ) { return ( e1 < e2 ); }

void rp(Elephant *e, int *pred, int i) 
{
    if (i >= 0 && pred[i] >= 0) {
        rp(e, pred, pred[i]);
    }
    printf("%d\n", e[i].index+1);
}


int main(int argc, char* argv[])
{
    Elephant e[N];
    int weight, iq, n = 0;
    

    while(scanf("%d %d", &weight, &iq) == 2) { 
        e[n].setData(n, weight, iq);
        n++;
    }
    
    sort(e, e+n, comparatorFunction);

    int pred[n],dp[n];
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        pred[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (e[i].w < e[j].w && e[i].s > e[j].s) {
                if (dp[i]+1 > dp[j]) {
                    dp[j] = dp[i]+1;
                    pred[j] = i;
                }
            }
        }
    }


    int lmax = 1;
    int pos = 0;

    for (int i = pos+1; i < n; i++) {
        if (dp[i] > lmax) {
            lmax = dp[i];
            pos = i;
        }
    }

    printf("%d\n", lmax);
    rp(e, pred, pos);
    

    return 0;
}