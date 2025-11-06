#!/bin/bash
if test $# -ne 0
then
	echo "Numero de argumentos incorrecto. Este script solo compila una libreria" ;
	exit 1 ;
fi

gcc -c libreria.c;

ar -rv liblibreria.a libreria.o

gcc -o test test.c -L. -llibreria

echo "Test compilado."

exit 0;