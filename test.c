#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>
int main(int argc, char *argv[]){
   int N ; 
    if (strcmp(argv[1], "head")==0) {
        N = 10;
        printf("Ejecutando head con N = %d\n", N);
        if (argc == 3) {
        N = atoi(argv[2]); 
        }
        head(N);
    }else{
        printf("Comando no reconocido.\n");
    }  
    

    return 0;
}
