SOURCES:= ${wildcard ./src/*.c} 

All: .PHONY unity.o

.PHONY:
	@echo "Compiling..."
	@echo ${SOURCES}

app:| ./Metadata.o ./_main.o
	gcc -o app ./Metadata.o ./_main.o
	mv *.o bins
	mv app targets

test:| ./Metadata.o ./test_Metadata.o ./unity.o
	gcc -o test ./Metadata.o ./test_Metadata.o ./unity.o
	mv *.o bins
	mv test targets

_main.o: ./src/_main.c
	gcc -c ./src/_main.c

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
