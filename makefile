.PHONY: clean

all: bin build calculator

calculator: bin/calculator

bin/calculator: build/cos.o build/sin.o build/tg.o build/ctg.o build/ex.o build/factorial.o bin build/Calc.o build/InfCalc.o
	gcc -Wall build/cos.o build/sin.o build/tg.o build/ctg.o build/ex.o build/factorial.o build/Calc.o build/InfCalc.o -o bin/calculator

build/cos.o: src/cos.c 
	gcc -Wall -lm  -c src/cos.c -o build/cos.o

build/sin.o: src/sin.c 
	gcc -Wall -lm  -c src/sin.c -o build/sin.o
build/tg.o: src/tg.c 
	gcc -Wall -lm  -c src/tg.c -o build/tg.o
build/ctg.o: src/ctg.c 
	gcc -Wall -lm  -c src/ctg.c -o build/ctg.o
build/ex.o: src/ex.c
	gcc -Wall -lm  -c src/ex.c -o build/ex.o
build/factorial.o: src/factorial.c
	gcc -Wall -lm  -c src/factorial.c -o build/factorial.o
build/Calc.o: src/Calc.c
	gcc -Wall -lm -c src/Calc.c -o build/Calc.o

build/InfCalc.o: src/InfCalc.c
	gcc -Wall -lm -c src/InfCalc.c -o build/InfCalc.o

build:
	mkdir build

bin:
	mkdir bin
clean:
	rm -rf build/*.o
