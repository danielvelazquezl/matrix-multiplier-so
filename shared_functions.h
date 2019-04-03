#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

#ifndef _SHARED_FUNCTIONS_H_
#define _SHARED_FUNCTIONS_H_

/*Reservar memoria para una matriz*/
int **reserveMemory(int order);
/*Escribir la matriz en un fichero*/
void writeMatrix(int **matrix, int order, char const *path);
/*Leer la matriz de un fichero*/
void readMatrix(int **matrix, int order, char const *path);
/*Obtener la orden de una matriz*/
int matrixOrder(char const *path);
/*Liberar memoria*/
void freeMemory(int **matrix, int order);
/*Imprimir matriz*/
void printMatrix(int **matrix, int order);
/*Calcular tiempo*/
double timeval_diff(struct timeval *a, struct timeval *b);

#endif