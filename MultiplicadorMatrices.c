#include <stdio.h>

//variable global para las iteraciones
int i, j, k;

/*
 * generacion de las 3 matrices inicializando 2 de ellas aleatoriamente y la tercera con valores que seran de la multiplicacion
 */
void principalParte2() {
	int **m1 = NULL,
		**m2 = NULL,
		**m3 = NULL,
		n;

	printf("Ingresa un tamanho para la matriz: ");
	scanf("%d", &n);
	printf("\n");

	m1 = (int **) calloc(n, sizeof(int*));// reserva de espacio para las filas de tamanho int*
	m2 = (int **) calloc(n, sizeof(int*));// al reservar inicializa a 0 las filas
	m3 = (int **) calloc(n, sizeof(int*));
	if ((m1 == NULL) && (m2 == NULL) && (m3 == NULL)) {//imprimira el error en caso de no contar con suficiente memoria
		perror("Error");
	}
	for (i = 0; i < n; i++) {
		m1[i] = (int *) calloc(n, sizeof(int));//reserva espacio para las columnas de tamanho int
		m2[i] = (int *) calloc(n, sizeof(int));
		m3[i] = (int *) calloc(n, sizeof(int));
		if ((m1[i] == NULL) && (m2[i] == NULL) && (m3[i] == NULL)) {
			perror("Error");
		}
	}

	//cargar las matrices aleatoriamente
	cargarMatriz(m1, n, 1);
	cargarMatriz(m2, n, 2);

	printf("Matriz 1: \n");
	imprimirMatriz(m1, n);

	printf("Matriz 2: \n");
	imprimirMatriz(m2, n);

	//multiplicar las matrices
	mulMatriz(m1, m2, m3, n);

	printf("Resultado de la multiplicacion: \n");
	imprimirMatriz(m3, n);

	//guardar los datos de la tercera matriz en un txt
	guardarArchivo(m3, n);

	//liberar memoria reservada siempre al termino del programa
	liberarMemoria(m1, m2, m3, n);
}

/*
 * funcion para imprimir el contenido de una matriz
 */
void imprimirMatriz(int **matriz, int n) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * funcion que carga la matriz con numeros en orden ascendente o descendente
 * dependiendo del control (1 = ascendente, !1 descendente);
 * donde un numero semilla es generado aleatoriamente y a partir de este van
 * cargando los numeros
 */
void cargarMatriz(int **matriz, int n, int control) {
	int numeros;
	srand(time(NULL));
	numeros = rand() % 10; //numero semilla aleatorio entre 1 y 100
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (control == 1) {
				*(matriz[i]+j) = numeros;
				numeros++;
			} else {
				numeros--;
				*(matriz[i]+j) = numeros;
			}
		}
	}
}

/*
 * funcion para multiplicar las matrices y cargarlos en otra
 */
void mulMatriz(int **mult1, int **mult2, int **destino, int n) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				*(destino[i]+j) += mult1[i][k] * mult2[k][j];
			}
		}
	}
}

/*
 * funcion para liberar la memoria de todos los punteros reservados
 * para las matrices
 */
void liberarMemoria(int **m1, int **m2, int **m3, int n) {
	for (i = 0; i < n; i++) {
		free(m3[i]);
		free(m2[i]);
		free(m1[i]);
	}
	free(m3);
	free(m2);
	free(m1);
}

/*
 * funcion para guardar la matriz resultante al archivo Resultado.txt
 */
 void guardarArchivo(int **matriz, int n) {
	 FILE *archivo = NULL;
	 archivo = fopen("Resultado.txt", "w");
	 if (archivo == NULL) {
		 perror("Error: ");
		 fclose(archivo);
	 }
	 fprintf(archivo, "%s", "Resultado de la multiplicacion:\n");
	 for (i = 0; i < n; i++) {
		 for (j = 0; j < n; j++) {
			 fprintf(archivo, "%d ", matriz[i][j]);
		 }
		 fprintf(archivo, "%s", "\n");
	 }
	 fclose(archivo);
 }
