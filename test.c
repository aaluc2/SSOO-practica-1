#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>
int main(int argc, char *argv[]){
   int N ; 
   if (argc==1) {
    printf("Error por uso incorrecto.\nFormato válido para %s: test -<función> [N lineas].\nSólo se podrán usar 3 funciones: 'head', 'tail' o 'longlines' e irán precedidas por un '-'.\nSi no se especifica número de lineas, se usarán 10 por defecto.\nSe lee de la entrada estándar(redireccionable).\n",argv[0]);
    exit(1);
   }
   
    if (strcmp(argv[1], "-head") == 0) {
        N = 10;
        if (argc == 3) {
        N = atoi(argv[2]); 
        }
        head(N);
    }else if (strcmp(argv[1], "-tail") == 0){
        N = 10;
        if (argc == 3) {
            N = atoi(argv[2]);
        }
        tail(N);
    }  else {
        printf("Error por uso incorrecto.\nFormato válido para %s: test -<función> [N lineas].\nSólo se podrán usar 3 funciones: 'head', 'tail' o 'longlines' e irán precedidas por un '-'.\nSi no se especifica número de lineas, se usarán 10 por defecto.\nSe lee de la entrada estándar(redireccionable).\n",argv[0]);
    }
    

    return 0;
}