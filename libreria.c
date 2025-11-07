#include <stdio.h>
#include <stdlib.h>


int head(int N) {
    if (N <= 0) {
        printf("head: invalid trailing option -- %d.\n", N);
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

int tail(int N) {
    FILE *fp = fopen("ftail.txt", "w");
    if (!fp) {
        printf("Error al abrir el fichero para escritura");
        return 0;
    }

    char buffer[1024];
    int contador = 0;
    int total = 0;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, fp);
        contador++;
    }
    fclose(fp);

    fp = fopen("ftail.txt", "r");

    total = contador - N;

    while (count < contador && fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (count >= total){
            fputs(buffer, stdout);  
        }
        count++;        
    }

    return 0;
}