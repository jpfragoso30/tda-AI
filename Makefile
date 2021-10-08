SOURCES:= ${wildcard ./src/*.c} 

All: .PHONY unity.o

.PHONY:
	@echo "Compiling..."
	@echo ${SOURCES}

app:| ./Metadata.o #...todos los .o necesarios (tambien despues de gcc ...) de implementacion
	gcc -o app ./Metadata.o
	mv *.o bins
	mv app targets

test:| ./unity.o ./test_Metadata.o ./Metadata.o
	gcc -o test ./unity.o ./test_Metadata.o ./Metadata.o
	mv *.o bins
	mv test targets

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