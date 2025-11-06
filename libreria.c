#include <stdio.h>
#include <stdlib.h>


int head(int N) {
    //No hace nada xd
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

int tail(int N) {
    int inicio;
    int count;
    if (N <= 0) {
        printf("El numero de lineas debe ser mayor que 0.\n");
        return 0;
    }

    if (N > 1024) {
        printf("El numero maximo de lineas soportado es 1024.\n");
        return 0;
    }

    char lineas[1024][1024];
    int total = 0;

    while (fgets(lineas[total % N], sizeof(lineas[0]), stdin) != NULL) {
        total++;
    }

    //Si total es 0 no tenemos nada que escribir y por eso se devuelve 0 directamente.
    if (total == 0) {
        return 0;
    }
    
    if (total > N) {
        inicio = total % N;
    } else {
        inicio = 0;
    }
    
    if (total < N) {
        count = total;
    } else {
        count = N;
    }

    for (int i = 0; i < count; i++) {
        int idx = (inicio + i) % N;
        fputs(lineas[idx], stdout);
    }

    return 0;
}