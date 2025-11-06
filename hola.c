#include <stdio.h>

int main(int argc, char *argv[]) {
    int arg = argc - 1;
    char aalic[100];
    int i;
    int count = 3;
    printf("Escribe algo: ");

    for (i = 0; i < count; i++)
    {
        fgets(aalic, 100, stdin);
        printf(aalic);
    }
    //No
    printf("Se han recibido %d argumentos.\n", arg);
    if (argc == 1){
        printf("No se ha recibido ningun argumento\n");
    } else if (argc > 3) {
        printf("No se puede usar esta funcion con tantos argumentos, maximo 2, deben ser enteros.\nError fatal.");
        return 1;
    }
    printf("Se ha recibido %s, como argumento",argv[0]);
    printf("%d \n", argc);
    printf("Hola, aaluc!\n");

    return 0;
}