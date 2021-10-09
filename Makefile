SOURCES:= ${wildcard ./*.c} 

#dependencies lists
METADATA_DEPENDENCY = ./Metadata.o

METADATA_FUNCTIONAL_DEPENDENCIES = ./agregarMetadatos.o ./guardarMetadatos.o ./eliminarMetadatos.o ./leerMetadatos.o
METADATA_DISPLAY_DEPENDENCIES = ./imprimir.o ./menuopciones.o

IMPLEMENTATION_DEPENDENCIES = ./_main.o
TESTING_DEPENDENCIES = ./test_Metadata.o ./unity.o

#compiling notification
All: .PHONY Metadata.o

.PHONY:
	@echo "Compiling..."
	@echo ${SOURCES}

#executables
app:| $(METADATA_DEPENDENCY) $(IMPLEMENTATION_DEPENDENCIES) $(METADATA_FUNCTIONAL_DEPENDENCIES) $(METADATA_DISPLAY_DEPENDENCIES)
	gcc -o app $(METADATA_DEPENDENCY) $(IMPLEMENTATION_DEPENDENCIES) $(METADATA_FUNCTIONAL_DEPENDENCIES) $(METADATA_DISPLAY_DEPENDENCIES)
	mv *.o bins
	mv ./app targets

test:| $(METADATA_DEPENDENCY) $(TESTING_DEPENDENCIES) $(METADATA_FUNCTIONAL_DEPENDENCIES)
	gcc -o test $(METADATA_DEPENDENCY) $(TESTING_DEPENDENCIES) $(METADATA_FUNCTIONAL_DEPENDENCIES)
	mv *.o bins
	mv ./test targets

#objects
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

#clean files
Clear_bins: ./bins/*
	rm ./bins/*

Clear_objects: ./*.o
	rm ./*.o

Clear_executables: ./test ./app
	rm ./test ./app

Clear_targets: ./targets/*
	rm ./targets/*
