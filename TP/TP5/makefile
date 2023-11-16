CC = gcc
OBJ = main.o TP5.o

.SILENT: MonProg run clean $(OBJ)

MonProg: $(OBJ)
	$(CC) $(OBJ) -o MonProg
main.o: main.c TP5.h
	$(CC) -c main.c
TP5.o: TP5.c TP5.h
	$(CC) -c TP5.c

run:
	./MonProg

clean :
	rm -f MonProg *.o
	echo "fichiers effacés"
