CC = gcc

all: compilar

compilar: main.o inicio.o menu.o fileIO.o
	$(CC) -o "Sistema de Registros Financeiros" main.o inicio.o menu.o fileIO.o dao.o operacoes.o userIO.o check.o
	
main.o: main.c
	$(CC) -c main.c
	
inicio.o: inicio.c
	$(CC) -c inicio.c
	
menu.o: menu.c
	$(CC) -c menu.c
	
fileIO.o: fileIO.c
	$(CC) -c fileIO.c
	
dao.o: dao.c
	$(CC) -c dao.c
	
operacoes.o: operacoes.c
	$(CC) -c operacoes.c
	
userIO.o: userIO.c
	$(CC) -c userIO.c

check.o: check.c
	$(CC) -c check.c
	
	
# $(CC) $(FILES) -o "Sistema de Registros Financeiros.exe"
	
#clean:
#	rm -rf *.o *~ compilar
