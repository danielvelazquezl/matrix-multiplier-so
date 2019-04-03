#include "shared_functions.h"

void multiply(int **a, int **b, int **res, int size);

int main(int argc, char const *argv[]){
	int **matrixA;
	int **matrixB;
	int **result;
	int order;
	struct timeval start, end;


	//Obtener orden de una sola matriz, por que son de igual orden
	order = matrixOrder(argv[1]);

	matrixA = reserveMemory(order);
	matrixB = reserveMemory(order);
	readMatrix(matrixA, order, argv[1]);
	readMatrix(matrixB, order, argv[2]);

    result = reserveMemory(order);

    gettimeofday(&start, NULL);
    //Mutiplicar
	multiply(matrixA, matrixB, result, order);
	//Obtener tiempo
	gettimeofday(&end, NULL);
	double t = timeval_diff(&end, &start);
    printf("tiempo: %.4g segundos\n", t);

    //Para depurar
	//printMatrix(matrixA, order);
	//printMatrix(matrixB, order);
	//printMatrix(result, order);

	writeMatrix(result, order, "resultado.txt");

	freeMemory(matrixA, order);
	freeMemory(matrixB, order);
	freeMemory(result, order);

	return 0;
}

void multiply(int **a, int **b, int **res, int size){
	int i,j,k;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){ 
			res[i][j]=0;
			for (k=0;k<size;k++){
				res[i][j]=res[i][j]+a[i][k]*b[k][j];
			}
		}
    }
}