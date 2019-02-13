
#include <stdio.h>
#include <stdlib.h>

static int times[1000], cross[2000], back[2000];
static int total_time, moves;


int getLine( char *s )
{
    int ch, counter=0;

    while( (ch=getchar()) != '\n' && ch != EOF) {*s++ = ch; ++counter;}

    *s = '\0';
    return counter;
}


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

void crossing(int a, int b, int i)
{
    cross[i++] = times[a];
    cross[i++] = times[b];
    total_time += (times[a] >= times[b]) ? times[a] : times[b];
    moves++;
}

void go_back(int a, int b) 
{
    back[a] = times[b];
    moves++;
    total_time += times[b];
}

int main(int argc, char *argv[]) 
{
    int num_cases,people,i,j,k,end;
    char buffer[256];
    scanf("%d", &num_cases);

    while (--num_cases >= 0) {
        end = 0;
        moves = 0;
        total_time = 0;
        scanf("%d", &people);
        for (i=0; i < people; i++) scanf("%d", &times[i]);
        getLine(buffer);
        while (getLine(buffer) > 0) {}
        
        qsort(times, people, sizeof(int), compare);
        i=0;
        j=0;
        k=people-1;
        while (!end) {
            switch (k)
            {
                case 0:
                    cross[i] = times[0];
                    moves++;
                    total_time += times[0];
                    end=1;
                    break;
                case 1:
                    crossing(0,1,i);
                    end=1;
                    break;
                case 2:
                    crossing(0,1,i);
                    i += 2;
                    go_back(j++, 0);
                    crossing(0,2,i);
                    end=1;
                    break;
                case 3:
                    if (2*times[1] < times[0]+times[k-1]) {
                        crossing(0,1,i);
                        i += 2;
                        go_back(j++, 0);
                        crossing(k-1,k,i);
                        i += 2;
                        k -= 2;
                        go_back(j++, 1);
                        crossing(0,1,i);
                    } else {        
                        crossing(0,k,i);
                        i += 2;
                        go_back(j++, 0);
                        crossing(0,k-1,i);
                        i += 2;
                        k -= 2;
                        go_back(j++, 0);
                        crossing(0,1,i);
                    }             
                    end=1;
                    break;
                    
                default:
                    if (2*times[1] < times[0]+times[k-1]) {
                        crossing(0,1,i);
                        i += 2;
                        go_back(j++, 0);
                        crossing(k-1,k,i);
                        i += 2;
                        k -= 2;
                        go_back(j++, 1);
                    } else {
                        crossing(0,k,i);
                        i += 2;
                        go_back(j++, 0);
                        crossing(0,k-1,i);
                        i += 2;
                        k -= 2;
                        go_back(j++, 0);
                    }
                    break;
            }  
        }
        
        printf("%d\n", total_time);
        for (i=0,j=0; i < moves-1; i+=2,j++) {
            printf("%d %d\n", cross[i], cross[i+1]);
            printf("%d\n", back[j]);
        }
        if (people > 1) printf("%d %d\n", cross[i], cross[i+1]);
        else printf("%d\n", cross[i]);
    
        if ( num_cases > 0 ) printf( "\n" );
        
    }
    

    
}