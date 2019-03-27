#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int orden; //tamanho de la matriz

int** reservarMemoria();
void cargarMatriz(int **matriz, char* nombre);
void imprimirMatriz(int **matriz);
void liberarMemoria(int **matriz);
void multiplicar(int **a, int **b, int **res);



/*********************************************************************************/
//Main de Parte 1. Descomentar para probar.

int main(){
	int **matrizA;
	int **matrizB;
	int **resultado;
	
	
	srand(time(NULL));
	printf("Ingrese el orden de la matriz: ");
	scanf("%d",&orden);
	matrizA = reservarMemoria();
	matrizB = reservarMemoria();

	cargarMatriz(matrizA, "mat_A.txt");

	FILE *infile; 
    // Open matriz_name.txt for reading 
    infile = fopen ("mat_A.txt", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file
    fread(matrizB[0], sizeof(int), 2, infile);
    fread(matrizB[1], sizeof(int), 2, infile); 
    //fread(&matrizB[0][1], sizeof(int), 1, infile);
   imprimirMatriz(matrizB);
  
    // close file 
    fclose (infile); 

	//cargarMatriz(matrizB);

	/*printf("Matriz A\n");
	imprimirMatriz(matrizA);
	printf("Matriz B\n");
	imprimirMatriz(matrizB);*/

	//multiplicar(matrizA, matrizB, resultado);

	//printf("Matriz resultante\n");
	//imprimirMatriz(resultado);

	liberarMemoria(matrizA);
	//liberarMemoria(matrizB);
	//liberarMemoria(resultado);

	system("PAUSE");
	return 0;
}


int** reservarMemoria(){
	int i;
	int **matriz = (int**) malloc(orden*sizeof(int*));
	for(i=0; i<orden; i++){
		matriz[i] = (int*) malloc(orden*sizeof(int));
	}
	return matriz;
}

void cargarMatriz(int **matriz, char* nombre){
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
			
			printf("%d ", matriz[i][j]);
		}
		fwrite(matriz[i], sizeof(int), 2, outfile);
		
	}
	
	if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");
	fclose(outfile);
}

void imprimirMatriz(int **matriz){
	int i, j;
	for (i=0; i<orden; i++){
		for (j=0;j<orden;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void liberarMemoria(int **matriz){
	int i;
	for(i=0; i<orden; i++){
		free(matriz[i]);
	}
	free(matriz);
}

void multiplicar(int **a, int **b, int **res){
	int i,j,k;
	for (i=0;i<orden;i++){
		for (j=0;j<orden;j++){ 
			res[i][j]=0;
			for (k=0;k<orden;k++){
				res[i][j]=res[i][j]+a[i][k]*b[k][j];
			}
		}
    }
}
