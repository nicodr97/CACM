
#include <stdio.h>
#include <string.h>

#define N_MAX 200

char names_original_disposition[N_MAX][100];
char names_target_disposition[N_MAX][100];
int target_positions[N_MAX];
int original_positions[N_MAX];


int getLine( char *s )
{
    int ch, n=0;

    while( (ch=getchar()) != '\n' && ch != EOF) s[n++] = ch;

    s[n] = '\0';

    return n;
}


int main(int argc, char *argv[])
{
    int num_cases, n, j, i, rc, highest_position;
    char buffer[256];

    rc = scanf("%d", &num_cases);
    
    while(--num_cases >= 0){
        rc = scanf("%d", &n);

        rc = getLine(buffer);

        for (i=0; i < n; i++) getLine(names_original_disposition[i]);
        for (i=0; i < n; i++) getLine(names_target_disposition[i]);

        for (i=0; i < n; i++) {
            for (j=0; j < n; j++) {
                if (0 == strcmp(names_original_disposition[i], names_target_disposition[j])) {
                    target_positions[i] = j;
                    original_positions[j] = i;
                    j=n+1;
                }
            }
        }

        highest_position = original_positions[n-1];
        for (i=n-2; i >= 0; i--) {
            if (original_positions[i] > highest_position) {
                break;
            } else {
                highest_position = original_positions[i];
            }
        }
        for (; i >= 0; i--) {
            printf("%s\n", names_target_disposition[i]);
        }
        printf("\n");

    }
    return 0;
}