#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void ejecutaHilo(void *id);

int varGlobal = 1000;

void main()
{
    pthread_t h1, h2;
    int v1 = 5, v2 = 6;
    int *r1 = NULL;
    int i;

    pthread_create(&h1, NULL, (void *)&ejecutaHilo, (void *)&v1);
    pthread_create(&h2, NULL, (void *)&ejecutaHilo, (void *)&v2);

    for (i = 0; i < 10; i++)
    {
        printf("Hilo principal, varGlobal= %d\n", varGlobal += 1);
        sleep(1);
    }

    pthread_join(h1, (void **)&r1);
    printf("hilo1 termina con: %d\n", *r1);
    pthread_join(h2, (void **)&r1);
    printf("hilo2 termina con: %d\n", *r1);
}

void ejecutaHilo(void *v)
{
    int *vh = (int *)(v);

    sleep(*vh);
    printf("Hilo que recibe %d, espera %ds, imprime varGlobal= %d, modifca val recibido\n", *vh, *vh, varGlobal);

    *vh = 5 * (*vh);

    pthread_exit(vh);
}
