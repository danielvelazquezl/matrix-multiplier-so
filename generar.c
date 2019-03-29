#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

//int orden; //tamanho de la matriz

int** reservarMemoria(int orden);
void cargarMatriz(int **matriz, int orden, char const *nombre);
void liberarMemoria(int **matriz, int orden);

/*********************************************************************************/
//Main de Parte 1. Descomentar para probar.

int main(int argc, char const *argv[]){
	int **matriz;
	int orden = atoi(argv[1]);
	srand(time(NULL));
	
	matriz = reservarMemoria(orden);
	cargarMatriz(matriz, orden, argv[2]);
	liberarMemoria(matriz, orden);

	//imprimirMatriz(matriz);
	return 0;
}


int** reservarMemoria(int orden){
	int i;
	int **matriz = (int**) malloc(orden*sizeof(int*));
	for(i=0; i<orden; i++){
		matriz[i] = (int*) malloc(orden*sizeof(int));
	}
	return matriz;
}

void cargarMatriz(int **matriz, int orden, char const *nombre){
	int i, j;
	FILE *outfile;
	outfile = fopen(nombre, "w");
	if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
	for (i=0; i<orden; i++){
		for (j=0;j<orden;j++){
			matriz[i][j]= rand()%6; //Numero aleatorio 0<=n<=5
			
		}
		fwrite(matriz[i], sizeof(int), orden, outfile);	
	}
	
	if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");
	fclose(outfile);
}


void imprimirMatriz(int **matriz, int orden){
	int i, j;
	for (i=0; i<orden; i++){
		for (j=0;j<orden;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void liberarMemoria(int **matriz,int orden){
	int i;
	for(i=0; i<orden; i++){
		free(matriz[i]);
	}
	free(matriz);
}
