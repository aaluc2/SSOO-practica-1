#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LineaLarga{
    char *linea;       
    size_t longitud;
} tLineaLarga;

int encontrar_mas_corta_idx(size_t *longitudes, int N) {
    int indice = 0;
    for (int i = 1; i < N; i++) {
        if (longitudes[i] < longitudes[indice]) {
            indice = i;
        }
    }
    return indice;
}

void ordenar_por_longitud(char **lineas, size_t *longitudes, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (longitudes[j] < longitudes[j + 1]) {
                size_t temp_len = longitudes[j];
                longitudes[j] = longitudes[j + 1];
                longitudes[j + 1] = temp_len;

                // Intercambiar punteros a líneas
                char *temp_linea = lineas[j];
                lineas[j] = lineas[j + 1];
                lineas[j + 1] = temp_linea;
            }
        }
    }
}

int head(int N) {
    //Inicializamos variables
    int contador = 0;
    size_t buffer_size = 4096;
    char *buffer = (char*) malloc(buffer_size);

    
    //Comprobaciones de la reserva de memoria y el argumento N
    if (buffer == NULL){
        printf("Error al reservar memoria en el buffer");
        return 7;
    }

    if (N <= 0) {
        printf("head: invalid trailing option -- %d.\n", N);
        return 6; 
    }    
    
    //Lectura de la entrada estándar, poniendo las primeras N líneas en salida estándar
    while (contador < N && fgets(buffer, buffer_size, stdin) != NULL) {
        fputs(buffer, stdout);  
        contador++;
    }
    //Liberamos memoria
    free(buffer);
    //Correcta ejecución del código, por lo que usamos return 0 para indicar el éxito
    return 0;
}

int tail(int N) {
    //Variables locales
    char buffer[1024];
    int contador = 0;
    int total = 0;
    int count = 0;

    //Comprobación de parámetros y aperturas de fichero
    if (N <= 0) {
        printf("tail: invalid trailing option -- %d.\n", N);
        return 9; 
    }

    FILE *fp = fopen("ftail.txt", "w");
    if (!fp) {
        printf("Error al abrir el fichero para escritura");
        return 10;
    }

    //Lectura de entrada estándar
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, fp);
        contador++;
    }
    fclose(fp);

    fp = fopen("ftail.txt", "r");

    //Ponemos en salida estándar las últimas líneas
    total = contador - N;

    while (count < contador && fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (count >= total){
            fputs(buffer, stdout);  
        }
        count++;        
    }
    //Correcta ejecución de la función, por lo que se usa return 0 para indicarlo
    return 0;
}

int longlines(int N) {
    //Variables locales
    int idx_reemplazar = 0;
    char buffer[4096];
    char **top_lineas = (char**)calloc(N, sizeof(char *)); //Array de punteros a char    
    size_t *top_longitudes =(size_t*) calloc(N, sizeof(size_t));

    //Comprobación reservas de memoria y parámetros pasados
    if (top_lineas == NULL || top_longitudes == NULL) {
        printf("Fallo al reservar memoria");
        free(top_lineas);
        free(top_longitudes);
        return 2;
    }  

    if (N <= 0) {
        printf("longlines: invalid trailing option -- %d.\n", N);
        return 1;
    }

    //Lectura entrada estándar para guardar en top_lineas las lineas más grandes
    while (fgets(buffer, 4096, stdin) != NULL) {

        size_t len_actual = strlen(buffer);

        //Usamos funcion auxiliar para encontrar el idx de la linea mas corta guardada
        int idx_reemplazar = encontrar_mas_corta_idx(top_longitudes, N);

        // Si no es mayor no se reemplaza nada y se sigue con la lectura
        if (len_actual > top_longitudes[idx_reemplazar]) { 
            // Liberamos la línea que vamos a reemplazar
            free(top_lineas[idx_reemplazar]); 
            top_lineas[idx_reemplazar] =(char*) malloc(len_actual + 1);   //+1 para el \0 del final        
            strcpy(top_lineas[idx_reemplazar], buffer);      
            top_longitudes[idx_reemplazar] = len_actual; //Nueva longitud en el idx antiguo
        }
    }
    //Imprimir, después de ordenar las líneas de mayor a menor por longitud
    ordenar_por_longitud(top_lineas, top_longitudes, N);
    for (int i = 0; i < N; i++) {
        if (top_lineas[i] != NULL) {
            fputs(top_lineas[i], stdout);
        }
    }
    //Liberar memoria
    for (int i = 0; i < N; i++) {
        free(top_lineas[i]);
    }
    free(top_lineas);     
    free(top_longitudes);

    //Correcta ejecución, código de salida 0
    return 0;
}