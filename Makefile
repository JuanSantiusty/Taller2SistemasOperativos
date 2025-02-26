#Compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
#Nombre del ejecutable
TARGET = gestionEmpresa
#Archivos objetos
OBJS = main.o empresa.o

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

#compila main.c a objeto (dependiente de empresa.h)
main.o: main.c empresa.h
	$(CC) $(CFLAGS) -c main.c

#Compila empresa.c a objeto (dependiente de empresa.h)
empresa.o: empresa.c empresa.h
	$(CC) $(CFLAGS) -c empresa.c

#Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
