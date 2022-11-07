#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t valRet;

    valRet = fork();
    
    if (valRet == -1)
    {
        printf("Error \n");
    }
    else
    {
        if (valRet == 0)
        {
            printf("Soy el proceso hijo, valRet = %d\n", valRet);
        }
        else
        {
            printf("Soy el proceso padre, valRet = %d \n", valRet);
        }
    }
    return 0;
}