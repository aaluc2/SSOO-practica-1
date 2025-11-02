#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>
int main(int argc, char *argv[]){
   int N ; 
   char error[]="Error: uso incorrecto.\nFormato valido: test -<funcion> [numero_de_lineas].\nSi no se especifica numero_de_lineas, se usaran 10 por defecto.\n";
   if (argc==1) {
    printf(error);
    exit(1);
   }
   
    if (strcmp(argv[1], "-head")==0) {
        N = 10;
        if (argc == 3) {
        N = atoi(argv[2]); 
        }
        printf("Ejecutando head con N = %d\n", N);
        head(N);
    }else{
        printf("Comando no reconocido.\n");
    }  
    

    return 0;
}