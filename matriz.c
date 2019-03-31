#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <math.h>

int **reserveMemory(int size);
void fillMatrix(int **matrix, int size, char const *path);
void freeMemory(int **matrix, int size);
void readMatrix(int **matrix, int size, char const *path);
int matrixOrder(char const *path);
void multiply(int **a, int **b, int **res, int size);

/*********************************************************************************/
//Main de Parte 1. Descomentar para probar.

int main(int argc, char const *argv[]){
	int **matrixA;
	int **matrixB;
	int **result;
	int order;

	order = matrixOrder(argv[1]);

	matrixA = reserveMemory(order);
	matrixB = reserveMemory(order);
	readMatrix(matrixA, order, argv[1]);
	readMatrix(matrixB, order, argv[2]);

	//imprimirMatriz(matrizA);
    //imprimirMatriz(matrizB);

    result = reserveMemory(order);
	multiply(matrixA, matrixB, result, order);
	fillMatrix(result, order, "resultado.txt");
	//leerMatriz(resultado, "resultado.txt");
	//imprimirMatriz(resultado);

	freeMemory(matrixA, order);
	freeMemory(matrixB, order);
	freeMemory(result, order);

	return 0;
}


int matrixOrder(char const *path){
	FILE *outfile;
	outfile = fopen(path, "r");
	fseek(outfile, 0L, SEEK_END);
	int order = sqrt(ftell(outfile)/4);
	//printf("test.c ocupa %d bytes", n);
	fclose(outfile);
	return order;
}

int **reserveMemory(int size)
{
	int i;
	int **matrix = (int **)malloc(size * sizeof(int *));
	for (i = 0; i < size; i++)
	{
		matrix[i] = (int *)malloc(size * sizeof(int));
	}
	return matrix;
}

void fillMatrix(int **matrix, int size, char const *path)
{
	int i, j;
	FILE *outfile;
	outfile = fopen(path, "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit(1);
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = rand() % 10; //random number from 0 to 9
			//printf("%d ", matrix[i][j]);
		}
		//printf("\n");
		fwrite(matrix[i], sizeof(int), size, outfile);
	}

	if (fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	fclose(outfile);
}


void readMatrix(int **matrix, int size, char const *path){
	FILE *infile; 
    // Open matriz_name.txt for reading 
    infile = fopen (path, "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file
    for(int i=0; i<size; i++){
    	fread(matrix[i], sizeof(int), size, infile);
    }
    fclose (infile); 
}


void freeMemory(int **matrix, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void multiply(int **a, int **b, int **res, int size){
	int i,j,k;
	/*FILE *outfile;
	outfile = fopen("resultado.txt", "w");
	if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } */
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){ 
			res[i][j]=0;
			for (k=0;k<size;k++){
				res[i][j]=res[i][j]+a[i][k]*b[k][j];
			}
		}
		//fwrite(res[i], sizeof(int), size, outfile);	
    }
    /*if(fwrite != 0) 
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");
	fclose(outfile);*/
}