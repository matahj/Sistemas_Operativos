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
#include <syscall.h>

void ejecutaHilo(void *id);

void main()
{
    pthread_t h1, h2;
    int id1 = 10, id2 = 20;

    pthread_create(&h1, NULL, (void *)&ejecutaHilo, (void *)&id1);
    printf("hilo1( %u) creado\n", (unsigned int)h1);

    pthread_create(&h2, NULL, (void *)&ejecutaHilo, (void *)&id2);
    printf("hilo2( %u) creado\n", (unsigned int)h2);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
}

void ejecutaHilo(void *id)
{
    int *idh = (int *)(id);

    int tid = syscall(SYS_gettid); // LLamada al sistema explícita, para obtener el id de Linux
    
    printf("Hilo en ejecución con idPosix= %u, idLinux= %d, idPrograma= %d\n", (int)pthread_self(), tid, *idh);
    
    sleep(7);

    pthread_exit(NULL);
}
