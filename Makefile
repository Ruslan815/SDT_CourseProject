.PHONY: clean

all: bin build build_test
test: bin/calculator_test

bin/calculator_test: build_test/main.o build_test/square.o build_test/percent.o build_test/calc.o build_test/cosinus.o
	gcc -Wall -Werror build_test/main.o build_test/square.o build_test/percent.o build_test/calc.o build_test/cosinus.o -o bin/calculator_test
build_test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build_test/main.o

build_test/square.o: src/square.c src/foo.h
	gcc -Wall -Werror -c -I thirdparty -I src src/square.c -o build_test/square.o
build_test/percent.o: src/percent.c src/foo.h
	gcc -Wall -Werror -c -I thirdparty -I src src/percent.c -o build_test/percent.o
build_test/calc.o: src/calc.c src/foo.h
	gcc -Wall -Werror -c -I thirdparty -I src src/calc.c -o build_test/calc.o
build_test/cosinus.o: src/cosinus.c src/foo.h
	gcc -Wall -Werror -c -I thirdparty -I src src/cosinus.c -o build_test/cosinus.o


build:
	mkdir build

bin:
	mkdir bin
build_test:
	mkdir build_test
clean:
	rm -rf build/*.o build_test/*.o bin/calculator_test
