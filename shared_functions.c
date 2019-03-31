#include "shared_functions.h"

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
			matrix[i][j] = rand() % 10;
		}
		fwrite(matrix[i], sizeof(int), size, outfile);
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