SOURCES:= ${wildcard ./*.c} 

ARCHIVOS_DEPENDENCIES = ./Archivos.o
METADATA_DEPENDENCIES = ./Metadata.o
VISTA_DEPENDENCIES = ./Vista.o

APP_DEPENDENCIES = ./_main.o

ARCHIVOS_TESTING_DEPENDENCIES = ./test_Archivos.o
METADATA_TESTING_DEPENDENCIES = ./test_Metadata.o

TESTING_DEPENDENCIES = ./unity.o

GENERATED = ./test_archivos ./test_metadatos ./app ./bins/* ./*.o ./targets/*

#compiling notification
All: .PHONY ./Metadata.o

.PHONY:
	@echo "Compiling..."
	@echo ${SOURCES}

#executables
app:| $(APP_DEPENDENCIES) $(ARCHIVOS_DEPENDENCIES) $(METADATA_DEPENDENCIES) $(VISTA_DEPENDENCIES)
	gcc -o app $(APP_DEPENDENCIES) $(ARCHIVOS_DEPENDENCIES) $(METADATA_DEPENDENCIES) $(VISTA_DEPENDENCIES)
	mv *.o bins
	mv ./app targets

test_archivos:| $(ARCHIVOS_TESTING_DEPENDENCIES) $(TESTING_DEPENDENCIES) $(ARCHIVOS_DEPENDENCIES) $(METADATA_DEPENDENCIES)
	gcc -o test_archivos $(ARCHIVOS_TESTING_DEPENDENCIES) $(TESTING_DEPENDENCIES) $(ARCHIVOS_DEPENDENCIES) $(METADATA_DEPENDENCIES)
	mv *.o bins
	mv ./test_archivos targets

test_metadatos:| $(METADATA_TESTING_DEPENDENCIES) $(TESTING_DEPENDENCIES) $(METADATA_DEPENDENCIES)
	gcc -o test_metadatos $(METADATA_TESTING_DEPENDENCIES) $(TESTING_DEPENDENCIES) $(METADATA_DEPENDENCIES)
	mv *.o bins
	mv ./test_metadatos targets

#objects
_main.o: ./src/_main.c
	gcc -c ./src/_main.c

Archivos.o: ./src/Archivos.c
	gcc -c ./src/Archivos.c

Metadata.o: ./src/Metadata.c
	gcc -c ./src/Metadata.c

Vista.o: ./src/Vista.c
	gcc -c ./src/Vista.c

test_Archivos.o: ./tests/test_Archivos.c
	gcc -c ./tests/test_Archivos.c

test_Metadata.o: ./tests/test_Metadata.c
	gcc -c ./tests/test_Metadata.c

unity.o: ./src/unity.c
	gcc -c ./src/unity.c

#clean files
clear:
	rm $(GENERATED)
