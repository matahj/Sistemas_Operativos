#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t valRet;
    int i, st, status;

    valRet = fork();

    switch (valRet)
    {
    case -1:
        printf("Error \n");
        exit(0);
        break;
    case 0:
        printf("hijo: Soy el proceso hijo, valRet = %d\n", valRet);
        printf("hijo: Mi pid es %d, el pid de mi padre es %d \n", getpid(), getppid());
        printf("hijo: Estoy trabajando ...\n");
        for (i = 0; i < 4; i++)
        {
            sleep(1);
        }
        printf("hijo: Dame un valor para regresarlo en el exit: ");
        scanf(" %d", &st);
        printf("hijo: Listo, bye.\n");
        exit(st);
    default:
        printf("padre: Soy el proceso padre, valRet = %d \n", valRet);
        printf("padre: Mi pid es %d, el pid de mi hijo es %d \n", getpid(), valRet);
        printf("padre: Estoy trabajando ...\n");
        for (i = 0; i < 4; i++)
        {
            sleep(1);
        }
        printf("padre: Estoy esperando a que mi hijo termine ...\n");
        wait(&status);
        printf("padre: Mi hijo terminó con el valor %d \n", WEXITSTATUS(status));
        printf("padre: Listo, bye.\n");
        break;
    }
    return 0;
}
