## Creación de procesos con fork()

Contenido:

* Ejemplos

```
ps -eo pid,user,comm | grep a.out | head -n 1 | awk '{print $1}' | xargs pstree -cp

```


