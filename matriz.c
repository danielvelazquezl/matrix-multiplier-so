#include "shared_functions.h"

void multiply(int **a, int **b, int **res, int size);

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