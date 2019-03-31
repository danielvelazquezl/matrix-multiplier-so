#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

#ifndef _SHARED_FUNCTIONS_H_
#define _SHARED_FUNCTIONS_H_

int **reserveMemory(int size);
void fillMatrix(int **matrix, int size, char const *path);
void readMatrix(int **matrix, int size, char const *path);
int matrixOrder(char const *path);
void freeMemory(int **matrix, int size);

#endif