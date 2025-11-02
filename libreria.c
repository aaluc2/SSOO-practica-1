#include <stdio.h>
#include <stdlib.h>


int head(const char *filename) {
    int N = 3;
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error al abrir el fichero");
        return 1;
    }

    char buffer[1024];  // Tamaño máximo por línea
    int count = 0;
    while (count < N && fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
        count++;
    }

    fclose(file);
    return 0;
}