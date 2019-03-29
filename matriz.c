#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int orden; //tamanho de la matriz

int** reservarMemoria();
void cargarMatriz(int **matriz, char* nombre);
void leerMatriz(int **matriz, char* nombre);
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
	cargarMatriz(matrizB, "mat_B.txt");
	liberarMemoria(matrizA);
	liberarMemoria(matrizB);

	matrizA = reservarMemoria();
	matrizB = reservarMemoria();
	leerMatriz(matrizA, "mat_A.txt");
	leerMatriz(matrizB, "mat_B.txt");

	imprimirMatriz(matrizA);
    imprimirMatriz(matrizB);

    resultado = reservarMemoria();
	multiplicar(matrizA, matrizB, resultado);
	leerMatriz(resultado, "resultado.txt");
	imprimirMatriz(resultado);

	liberarMemoria(matrizA);
	liberarMemoria(matrizB);
	liberarMemoria(resultado);

	short i= 5;
	short c= 95;
	FILE *outfile;
	outfile = fopen("mat_A.txt", "r");
	//fwrite(&i, sizeof(short), 1, outfile);
	//fwrite(&c, sizeof(short), 1, outfile);
	fseek(outfile, 0L, SEEK_END);
  	printf("test.c ocupa %d bytes", ftell(outfile)/4);
	fclose(outfile);

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
		fwrite(matriz[i], sizeof(int), orden, outfile);	
	}
	
	if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");
	fclose(outfile);
}

void leerMatriz(int **matriz, char* nombre){
	FILE *infile; 
    // Open matriz_name.txt for reading 
    infile = fopen (nombre, "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file
    for(int i=0; i<orden; i++){
    	fread(matriz[i], sizeof(int), orden, infile);
    }
    fclose (infile); 
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
	FILE *outfile;
	outfile = fopen("resultado.txt", "w");
	if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
	for (i=0;i<orden;i++){
		for (j=0;j<orden;j++){ 
			res[i][j]=0;
			for (k=0;k<orden;k++){
				res[i][j]=res[i][j]+a[i][k]*b[k][j];
			}
		}
		fwrite(res[i], sizeof(int), orden, outfile);	
    }
    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");
	fclose(outfile);
}