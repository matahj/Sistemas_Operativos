#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t valRet;
    int n;
    int i = -5;
    int x = -5;

    srand(time(NULL));
    n = rand() % 8 + 1;

    printf("Altura = %d (%d niveles). \n", n, n+1);

    for (i = 0; i < n; i++)
    {
        x = fork();
        if (x != 0)
            break;
    }

    printf("pid= %d, i= %d, x= %d \n", getpid(), i, x);
    
    sleep(10);
    
    return 0;
}