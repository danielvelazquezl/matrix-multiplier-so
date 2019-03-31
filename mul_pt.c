#include <stdlib.h>
#include "shared_functions.h"

typedef struct _params
{
    long id;
    int order;
    int threads;
    int **mA;
    int **mB;
    int **result;
} params;

void *matmul(params *p)
{

    int i, j, k;
    int rows_per_thr = p->order / p->threads;
    int start_index = p->id * rows_per_thr;
    int final_index = (p->id + 1) * rows_per_thr;

    for (i = start_index; i < final_index; i++)
    {
        for (j = 0; j < p->order; j++)
        {
            for (k = 0; k < p->order; k++)
            {
                p->result[i][j] += p->mA[i][k] * p->mB[k][j];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int threads = atoi(argv[3]);
    int order = matrixOrder(argv[1]);
    int **mA = reserveMemory(order);
    int **mB = reserveMemory(order);
    int **result = reserveMemory(order);
    srand(time(NULL));
    pthread_t tid[threads];
    int i, j;
    long rank;

    readMatrix(mA, order, argv[1]);
    readMatrix(mB, order, argv[2]);

    params ps[threads];
    params p = {0, order, threads, mA, mB, result};

    //Creación de threads
    for (rank = 0; rank < threads; rank++)
    {
        p.id = rank;
        ps[rank] = p;
        pthread_create(&tid[rank], NULL, (void *)matmul, (void *)&ps[rank]);
    }

    //Unión de threads
    for (rank = 0; rank < threads; rank++)
        pthread_join(tid[rank], NULL);

    printf("\n Matriz resultado: \n");
    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    freeMemory(mA, order);
    freeMemory(mB, order);
    freeMemory(result, order);

    // Fin de proceso padre
    pthread_exit(NULL);
    return 0;
}
