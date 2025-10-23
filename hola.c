#include <stdio.h>

int main(int argc, char *argv[]) {
    int arg = argc - 1;
    int x;
    printf("Se han recibido %d argumentos.\n", arg);
    if (argc == 1){
        printf("No se ha recibido ningun argumento\n");
    } else if (argc > 3) {
        printf("No se puede usar esta funcion con tantos argumentos, maximo 2, deben ser enteros.\nError fatal.");
        return 1;
    }
    printf("%d \n", argc);
    printf("Hola, aaluc!\n");
    scanf("%d", &x);
    printf("El numero es: %d\n", x);
    return 0;
}