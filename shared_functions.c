#include "shared_functions.h"

int **reserveMemory(int order)
{
	int i;
	int **matrix = (int **)malloc(order * sizeof(int *));
	for (i = 0; i < order; i++)
	{
		matrix[i] = (int *)malloc(order * sizeof(int));
	}
	return matrix;
}


void writeMatrix(int **matrix, int order, char const *path){
	int i, j;
	FILE *outfile;
	outfile = fopen(path, "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit(1);
	}
	for (i = 0; i < order; i++)
	{
		fwrite(matrix[i], sizeof(int), order, outfile);
	}

	if (fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	fclose(outfile);
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


void readMatrix(int **matrix, int order, char const *path){
	FILE *infile; 
    // Open matriz_name.txt for reading 
    infile = fopen (path, "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file
    for(int i=0; i<order; i++){
    	fread(matrix[i], sizeof(int), order, infile);
    }
    fclose (infile); 
}

void freeMemory(int **matrix, int order)
{
	int i;
	for (i = 0; i < order; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void printMatrix(int **matrix, int order)
{
	int i, j;
	for (i = 0; i < order; i++)
	{
		for (j = 0; j < order; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}