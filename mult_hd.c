#include <stdlib.h>
#include "shared_functions.h"

pthread_mutex_t mutexmul;

/*Parametros para la funcion multiplicar*/
typedef struct _params
{
    long id;
    int order;
    int threads;
    FILE *mat_A;
    FILE *mat_B;
    int **result;
} params;


int getPosition(int i, int j, int order){
    return ((i*order)+j)*4;
}

void *multiply(params *p)
{
    int i, j, k, numA, numB;
    //Numero de filas para cada thread
    int rows_per_thr = p->order / p->threads;
    //Posicion de inicio y fin
    int start_index = p->id * rows_per_thr;
    int final_index = (p->id + 1) * rows_per_thr;

    for (i = start_index; i < final_index; i++)
    {
        for (j = 0; j < p->order; j++)
        {
            for (k = 0; k < p->order; k++)
            {
                //Bloquear recurso
                pthread_mutex_lock (&mutexmul);
                //Ir a posicion de los archivos y leer
                fseek(p->mat_A, getPosition(i,k,p->order), SEEK_SET);
                fseek(p->mat_B, getPosition(k,j,p->order), SEEK_SET);
                fread(&numA, sizeof(int), 1, p->mat_A);
                fread(&numB, sizeof(int), 1, p->mat_B);

                p->result[i][j] +=  numA* numB;
                //Desbloquear
                pthread_mutex_unlock (&mutexmul);
                
            }
        }
    }
}


int main(int argc, char *argv[])
{
    FILE *matriz_A, *matriz_B;
    struct timeval start, end;
    //Numero de threads
    int threads = atoi(argv[3]);
    int order = matrixOrder(argv[1]);
    //Abrir archivos
    matriz_A = fopen(argv[1], "r");
    matriz_B = fopen(argv[2], "r");
    int **result = reserveMemory(order);

    pthread_t tid[threads];
    int i, j;
    long rank;

    //Inicializar mutex
    pthread_mutex_init(&mutexmul, NULL);
    //Array de parametros
    params ps[threads];
    params p = {0, order, threads, matriz_A, matriz_B, result};

    //Creación de threads
    gettimeofday(&start, NULL);
    for (rank = 0; rank < threads; rank++)
    {
        p.id = rank;
        ps[rank] = p;
        pthread_create(&tid[rank], NULL, (void *)multiply, (void *)&ps[rank]);
    }

    //Unión de threads
    for (rank = 0; rank < threads; rank++)
        pthread_join(tid[rank], NULL);
    
    gettimeofday(&end, NULL);

    double t = timeval_diff(&end, &start);
    printf("tiempo: %.4g segundos\n", t);

    //printMatrix(result, order);
    writeMatrix(result, order, "resultado.txt");

    fclose(matriz_A);
    fclose(matriz_B);
    freeMemory(result, order);

    pthread_mutex_destroy(&mutexmul);
    // Fin de proceso padre
    pthread_exit(NULL);
    return 0;
}
