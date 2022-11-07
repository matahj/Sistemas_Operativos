#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int op;
    int cont = 0, i, status;
    char *argsv[] = {"/usr/bin/xterm", "-title", "Ejecutando exev", "-fn", "9x15", "-e", "./hola", "Jorge", NULL};
    char *argsvp[] = {"xterm", "-title", "Ejecutando exevp", "-fn", "9x15", "-e", "./hola", "Jorge", NULL};

    do
    {
        printf("1.- execl\n");
        printf("2.- execlp\n");
        printf("3.- execv\n");
        printf("4.- execvp\n");
        printf("5.- finalizar proceso padre\n");
        printf("Seleccione la función a utilizar: ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            cont++;
            if (fork() == 0) // se crea un proceso hijo para ejecutar el programa (será sobreescrito)
                execl("/usr/bin/xterm", "/usr/bin/xterm", "-title", "Ejecutando exec", "-fn", "9x15", "-e", "./hola", "Jorge", NULL);
            break;
        case 2:
            cont++;
            if (fork() == 0)
                execlp("xterm", "xterm", "-title", "Ejecutando exec", "-fn", "9x15", "-e", "./hola", "Jorge", NULL);
            break;
        case 3:
            cont++;
            if (fork() == 0)
                execv("/usr/bin/xterm", argsv);
            break;
        case 4:
            cont++;
            if (fork() == 0)
                execvp("xterm", argsvp);
            break;
        case 5:
            printf("Terminando...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    } while (op != 5);

    printf("Esperando a que finalicen todos los hijos...\n");
    for (i = 0; i < cont; i++)
    {
        wait(&status);
    }

    printf("Terminando\n");

    return 0;
}
