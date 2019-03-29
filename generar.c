#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **reserveMemory(int size);
void cargarmatrix(int **matrix, int size, char const *path);
void freeMemory(int **matrix, int size);

int main(int argc, char const *argv[])
{
	int **matrix;
	int size = atoi(argv[1]);
	//srand(time(NULL));

	matrix = reserveMemory(size);
	cargarmatrix(matrix, size, argv[2]);
	freeMemory(matrix, size);

	return 0;
}

//reserve
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

void cargarmatrix(int **matrix, int size, char const *path)
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
		}
		fwrite(matrix[i], sizeof(int), size, outfile);
	}

	if (fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");
	fclose(outfile);
}

void printMatrix(int **matrix, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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
