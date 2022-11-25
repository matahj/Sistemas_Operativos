#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int almacen = -1;       // almacén de tamaño 1 inicialmente vacío
pthread_mutex_t c1, c2; // candados abiertos por omisión

void productor(void *p);
void consumidor(void *p);

void main()
{
    pthread_t hilo1, hilo2;
    void *resp;

    srand(time(NULL));

    //inicialización de los candados
    pthread_mutex_unlock(&c2);
    pthread_mutex_lock(&c2);

    pthread_create(&hilo2, NULL, (void *)&consumidor, (void *)NULL);
    pthread_create(&hilo1, NULL, (void *)&productor, (void *)NULL);

    pthread_join(hilo1, &resp);
    pthread_join(hilo2, &resp);
}

void productor(void *p)
{
    int producto = 0;
    int t_produccion;

    while (1)
    {
        t_produccion = rand()%8 + 1;
        producto++;
        sleep(t_produccion);

        pthread_mutex_lock(&c1);
            printf("***********************************\n");
            printf("Productor almacenando %d\n",producto);
            almacen = producto;
        pthread_mutex_unlock(&c2);

    }
}

void consumidor(void *p)
{
    int producto = -1;
    int t_consumo;

    while (1)
    {
        pthread_mutex_lock(&c2);
            producto = almacen;
            printf("Consumidor obteniendo %d\n", producto);
            printf("***********************************\n");
        pthread_mutex_unlock(&c1);
        
        t_consumo = rand()%8 + 1;
        producto=-1;
        sleep(t_consumo);
    }
    
}