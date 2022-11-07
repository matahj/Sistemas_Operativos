/*
Compilación y ejecución:
gcc 1ejhilos.c -lpthread
./a.out
Para ver el árbol de procesos:
ps -eo pid,user,comm|grep a.out | head -n 1 | awk '{print $1}' | xargs pstree -cp
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void ejecutaHilo();

void main()
{
    pthread_t h1, h2;

    pthread_create(&h1, NULL, (void *)&ejecutaHilo, NULL);
    pthread_create(&h2, NULL, (void *)&ejecutaHilo, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
}

void ejecutaHilo()
{
    printf("Hilo en ejecución...\n");
    sleep(5);
    pthread_exit(NULL);
}
