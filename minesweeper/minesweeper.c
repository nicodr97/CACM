#include <stdio.h>
#include <string.h>

static int field[100][100];


int main(int argc, char *argv[])
{
    int m,n,i,j,ch;
    int field_num=1;
    while(scanf("%d%d\n", &m, &n) > 0 && !(m == 0 && n == 0)) {
        for(i=0; i<m;i++) {
            for(j=0; j<n; j++) {
                field[i][j] = 0;
            }
        }
        if(field_num>1) printf("\n");
        printf("Field #%d:", field_num++);
        for(i=0; i<m; i++) {
            j=0;
            while((ch = getchar()) != '\n') { 
                if(ch == '*') {
                    field[i][j] = -10;
                    if(i==0) { /* First line */
                        if(j==0) { /* First column */
                            field[i][j+1]++;
                            field[i+1][j]++;
                            field[i+1][j+1]++;
                        } else if(j==n-1) { /* Last column */
                            field[i][j-1]++;
                            field[i+1][j]++;
                            field[i+1][j-1]++;
                        } else { /* Center columns */
                            field[i][j-1]++;
                            field[i][j+1]++;
                            field[i+1][j-1]++;
                            field[i+1][j]++;
                            field[i+1][j+1]++;
                        }
                    } else if(i==m-1) { /* Last line */
                        if(j==0) { /* First column */
                            field[i][j+1]++;
                            field[i-1][j]++;
                            field[i-1][j+1]++;
                        } else if(j==n-1) { /* Last column */
                            field[i][j-1]++;
                            field[i-1][j]++;
                            field[i-1][j-1]++;
                        } else { /* Center columns */
                            field[i][j-1]++;
                            field[i][j+1]++;
                            field[i-1][j-1]++;
                            field[i-1][j]++;
                            field[i-1][j+1]++;
                        }
                    } else { /* Center lines */
                        if(j==0) { /* First column */
                            field[i-1][j]++;
                            field[i-1][j+1]++;
                            field[i][j+1]++;
                            field[i+1][j+1]++;
                            field[i+1][j]++;
                        } else if(j==n-1) { /* Last column */
                            field[i-1][j]++;
                            field[i-1][j-1]++;
                            field[i][j-1]++;
                            field[i+1][j-1]++;
                            field[i+1][j]++;
                        } else { /* Center columns */
                            field[i-1][j-1]++;
                            field[i-1][j]++;
                            field[i-1][j+1]++;
                            field[i][j-1]++;
                            field[i][j+1]++;
                            field[i+1][j-1]++;
                            field[i+1][j]++;
                            field[i+1][j+1]++;
                        }
                    }
                    
                } 
                j++;
            }
        }
        for(i=0; i<m;i++) {
            printf("%c", '\n');
            for(j=0; j<n; j++) {
                if(field[i][j]<0) printf("%c", '*');
                else printf("%d", field[i][j]);
            }
        }
        printf("\n");
    }
 
    return 0;
}
