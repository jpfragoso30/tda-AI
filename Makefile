SOURCES:= ${wildcard ./src/*.c} 

All: .PHONY unity.o

.PHONY:
	@echo "Compiling..."
	@echo ${SOURCES}

app:| ./Metadata.o ./_main.o agregarMetadatos.o guardarMetadatos.o imprimir.o eliminarMetadatos.o leerMetadatos.o menuopciones.o
	gcc -o app ./Metadata.o ./_main.o agregarMetadatos.o guardarMetadatos.o imprimir.o eliminarMetadatos.o leerMetadatos.o menuopciones.o
	mv *.o bins
	mv app targets

test:| ./Metadata.o ./test_Metadata.o ./unity.o agregarMetadatos.o guardarMetadatos.o imprimir.o eliminarMetadatos.o leerMetadatos.o menuopciones.o
	gcc -o test ./Metadata.o ./test_Metadata.o ./unity.o agregarMetadatos.o guardarMetadatos.o imprimir.o eliminarMetadatos.o leerMetadatos.o menuopciones.o
	mv *.o bins
	mv test targets

_main.o: ./src/_main.c
	gcc -c ./src/_main.c

agregarMetadatos.o: ./src/agregarMetadatos.c
	gcc -c ./src/agregarMetadatos.c

guardarMetadatos.o: ./src/guardarMetadatos.c
	gcc -c ./src/guardarMetadatos.c

imprimir.o: ./src/imprimir.c
	gcc -c ./src/imprimir.c

leerMetadatos.o: ./src/leerMetadatos.c
	gcc -c ./src/leerMetadatos.c

eliminarMetadatos.o: ./src/eliminarMetadatos.c
	gcc -c ./src/eliminarMetadatos.c

menuopciones.o: ./src/menuopciones.c
	gcc -c ./src/menuopciones.c

Metadata.o: ./src/Metadata.c
	gcc -c ./src/Metadata.c

test_Metadata.o: ./tests/test_Metadata.c
	gcc -c ./tests/test_Metadata.c

unity.o: ./src/unity.c
	gcc -c ./src/unity.c

Clear_bins: ./bins/*
	rm ./bins/*

Clear_objects: ./*.o
	rm ./*.o

Clear_targets: ./targets/*
	rm ./targets/*
