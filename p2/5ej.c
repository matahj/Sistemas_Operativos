#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t valRet;
    pid_t pidPadre = getpid();
    int n;
    int i = -5;
    int x = -5;
    int contador = 0, j, status;

    srand(time(NULL));
    n = rand() % 8 + 1;

    printf("N = %d \n", n);

    for (i = 1; i <= n; i++)
    {
        x = fork();
        if (x == 0)
            break;
    }

    printf("pid= %d, i= %d, x= %d \n", getpid(), i, x);
    sleep(10);

    if (pidPadre != getpid())
    {
        exit(1);
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            wait(&status);
            contador = contador + WEXITSTATUS(status);
        }

        printf("Fueron %d descendientes\n", contador);
    }

    return 0;
}