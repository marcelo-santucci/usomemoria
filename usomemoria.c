/*
    Sistemas Operativos
    Ilustrar el uso de memoria por parte de los programas

 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

long obtenerUsoMemoria() {
    struct rusage miuso;
    
    getrusage(RUSAGE_SELF, &miuso);
    return miuso.ru_maxrss;
}

int main () {
    long lineaBase = obtenerUsoMemoria();

    for (int i=0; i < 20; i++) {

        /*
        1. Compilar con todos los comentarios y ejecutar
        2. Descomentar unicamente la línea de Reserva malloc, compilar y ejecutar
            No se ve que se incremente el uso de memoria
        3. Descomentar tambien la linea de Asignación memset, compilar y ejecutar
            Ya se ve que se incrementa el uso de memoria
        
        */

        //Línea de Reserva malloc 
        //char *p = malloc(1024*100);     // <-- Linea malloc
        
        //Línea Asignacion memset
        //memset(p, 1, 1024*100);         // <-- Linea memset

        //Linea para hacer lenta la ejecución y poder comparar con el uso de "ps ux"
        //sleep(1);

        printf("Uso: %ld + %ld \n", lineaBase, obtenerUsoMemoria()-lineaBase);
    }
}