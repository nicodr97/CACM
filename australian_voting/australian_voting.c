#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20

static int total_votes[1000][MAX_CANDIDATES];
static char cand_names[MAX_CANDIDATES][100];
int cand_votes[MAX_CANDIDATES];
int active_cand[MAX_CANDIDATES];


int getLine( char *s )
{
    int ch, counter=0;

    while( (ch=getchar()) != '\n' && ch != EOF) {*s++ = ch; ++counter;}

    *s = '\0';

    return counter;
}


int main()
{
    int num_cases,num_cand,i,rc,num_votes,k,end,min,max;
    char temp[256], *tok;

    rc = scanf("%d", &num_cases);
    


    while( --num_cases >= 0) {

        rc = scanf( "%d", &num_cand);
        getLine(temp); /* for jumping to the next line */

        for(i = 0; i < num_cand; i++) getLine(cand_names[i]);

        num_votes=0;
        while(getLine(temp) > 0) {
            tok = strtok(temp, " ");
            for(i = 0; tok != NULL; i++) {
                total_votes[num_votes][i] = atoi(tok)-1;
                tok = strtok(NULL, " ");
            }
            num_votes++;
        }
        
        for(i = 0; i < num_cand; i++) active_cand[i] = 1;
        
        
        end = !(num_cand > 0 && num_votes > 0);
        while(!end) {
            for(i = 0; i < num_cand; i++) cand_votes[i] = 0;
            for(i = 0; i < num_votes; i++) {
                for(k = 0; k < num_cand; k++) {
                    if(active_cand[total_votes[i][k]]) {
                        cand_votes[total_votes[i][k]]++;
                        break;
                    } 
                }
            }

            min = 1000;
            max = -1;

            for(i=0; i < num_cand; i++) {
                if(active_cand[i]) {
                    if(cand_votes[i] < min) {
                        min = cand_votes[i];
                    }
                    if(cand_votes[i] > max) {
                            max = cand_votes[i];
                    }
                }
            }
            
            if(max == min) {
                for(i=0; i < num_cand; i++) {
                    if(active_cand[i]) {
                        printf("%s\n", cand_names[i]);
                    }
                }
                end = 1;
            } else {
                for(i=0; i < num_cand && !end; i++) {
                    if(active_cand[i]) {
                        if(2*cand_votes[i] >= num_votes) {
                            printf("%s\n", cand_names[i]);
                            end = 1;
                        } else if(cand_votes[i] == min) {
                            active_cand[i] = 0;
                        }
                    }
                }  
            }
        }
        
    if ( num_cases > 0 ) printf( "\n" );
        
    }

    


    return 0;
}
