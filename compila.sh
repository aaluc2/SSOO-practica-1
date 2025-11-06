#!/bin/bash
#Verificar que no se hayan pasado argumentos al script
if test $# -ne 0
then
	echo "Numero de argumentos incorrecto. Este script solo compila una libreria" ;
	exit 1 ;
fi
#Obtener el fichero objeto (libreria.o).

gcc -c libreria.c;

#Crear la libreria estatica (liblibreria.a) que contiene el objeto libreria.o

ar -rv liblibreria.a libreria.o

#Compila el archivo test.c y lo enlaza con la biblioteca liblibreria.a

gcc -o test test.c -L. -llibreria

echo "Test compilado."

exit 0;