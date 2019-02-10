#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_P	30

int	pila[ MAX_P+2 ], pila_original[ MAX_P+2 ];
int	tamanyo;

void procesa_linea( char *s )
{
	int		i;
	char	*p;
	tamanyo=0;

	while( *s != '\0' ) {
		
		while( *s != '\0'  &&  !isdigit( *s ) ) s++;
		p=s;
		while( *s != '\0'  &&  isdigit( *s ) ) s++;
		*s='\0';
		if ( p < s ) pila[tamanyo++] = atoi( p );
		s++;
	}

	for( i=0; i < tamanyo; i++ ) pila_original[tamanyo-1-i] = pila[i];
	for( i=0; i < tamanyo; i++ ) pila[i] = pila_original[i];
}

void guarda_original()
{
	int	i;

	for( i=tamanyo-1; i >= 0; i-- ) fprintf( stdout, "%d ", pila[i] );
	fprintf( stdout, "\n" );
}




void flipa( int n )
{
/* Se puede invocar dentro de ordena() para simplificar */
	int i = n;
	int j = tamanyo-1;
	int aux;
	while (i < j) {
		aux = pila[i];
		pila[i] = pila[j];
		pila[j] = aux;
		i++;
		j--;
	}
}

/*
Damos la vuelta en la posición del mayor no ordenado y damos otra vuelta en la posición que le corresponde, es
decir, la siguiente al último mayor ordenado
*/

void ordena()
{
/* Debe mostrar la secuencia de cambiazos */
/* Es casi un ordenaci�n por selecci�n directa */
	int flips[2*tamanyo],i,max;
	int nflips = 0;
	int not_ordered = 0; /*  pos del primer elemento de la parte de la pila no ordenada*/
	while (not_ordered < tamanyo-1) {
		max = not_ordered;
		for (i=not_ordered+1; i < tamanyo; i++) if(pila[i] > pila[max]) max = i;
		if (max != not_ordered) {
			if (max < tamanyo-1) {
			flipa(max);
			flips[nflips++] = max;
			}
			flipa(not_ordered);
			flips[nflips++] = not_ordered;
		}
		not_ordered++;
		
	}
	for (i=0; i < nflips; i++) printf("%d ", flips[i]+1);
}

int main( int arc, char *argv[] )
{
	char	buffer[1024];
	int i;

	while( fgets( buffer, 1020, stdin ) != NULL ) {
		procesa_linea( buffer );
		guarda_original();
		ordena();
		fprintf( stdout, "0\n" );
	}

	return 0;
}
