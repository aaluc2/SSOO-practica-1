#include <stdio.h>
#include <stdlib.h>


int head(int N) {
    if (N <= 0) {
        printf("El numero de lineas debe ser mayor que 0.\n");
        return 0; 
    }
    char buffer[1024];     
    int contador = 0;

    
    while (contador < N && fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, stdout);  
        contador++;
    }

    return 0;
}
