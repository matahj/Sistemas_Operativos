## Creación de procesos con fork()

Contenido:

* Ejemplos

Con el siguiente comando se puede ver el árbol de procesos, mientras el programa con fork's se está ejecutando.

```
ps -eo pid,user,comm | grep a.out | head -n 1 | awk '{print $1}' | xargs pstree -cp 

```

