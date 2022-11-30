/*  Un productor y un consumidor con
    almacén de tamaño TAM.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define TAM 10

int almacen[TAM];          // almacén de tamaño TAM
sem_t espacios, elementos; // semáforos

void productor(void *p);
void consumidor(void *p);

void main()
{
    pthread_t hilo1, hilo2; // hilo productor y consumidor
    void *resp;

    srand(time(NULL));

    // inicialización de los semaforos
    sem_init(&espacios, 0, TAM);  // indica cuantos espacios libres hay en el arreglo
    sem_init(&elementos, 0, 0); // indica cuantos productos hay en el arreglo

    pthread_create(&hilo1, NULL, (void *)&productor, (void *)NULL);
    pthread_create(&hilo2, NULL, (void *)&consumidor, (void *)NULL);

    pthread_join(hilo1, &resp);
    pthread_join(hilo2, &resp);
}

void productor(void *p)
{
    int producto = 0; 
    int pos = 0;

    while (1)
    {
        producto++; // producción

        sem_wait(&espacios); // decrementa el semáforo (número de espacios)
            printf("Produciendo: %d en almacen[%d]\n", producto, pos);
            almacen[pos] = producto;
            pos = (pos + 1) % TAM;
        sem_post(&elementos); // incrementa el semáforo (número de productos)

        sleep(2); //retardo de producción
    }
}

void consumidor(void *p)
{
    int producto = -1;
    int pos = 0;

    while (1)
    {
        sem_wait(&elementos);    // decrementa el semáforo (número de elementos)
            producto = almacen[pos]; // saca producto del almacén
            almacen[pos] = -1;
            printf("*********Consumiendo: %d de almacen[%d]\n", producto, pos);
            pos = (pos + 1) % TAM;
        sem_post(&espacios); // incrementa el semáforo (número de espacios)

        sleep(2); // retardo de consumo
    }
}