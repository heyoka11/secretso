#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 100000
#define T 4

int sum = 0;
pthread_mutex_t mtx;

void *array_sum(void *arg)
{
    int *A = (int*)arg; // cast void* --> int*
    int i;
    for (i = 0; i < N/T; i++){
        pthread_mutex_lock(&mtx);
        sum += A[i];
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t[T];
    pthread_mutex_init(&mtx, NULL);
    int A[N], i;
    for (i = 0; i < N; i++)
        A[i] = rand()%10;
    for (i = 0; i < T; i++)
        pthread_create(&t[i], NULL, array_sum, &A[i*N/T]);
    for (i = 0; i < T; i++)
        pthread_join(t[i], NULL);
    printf("%d\n", sum); // 448706
    return 0;
}
