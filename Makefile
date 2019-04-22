.PHONY: clean

all: bin build build_test
build:
	mkdir build

bin:
	mkdir bin
build_test:
	mkdir build_test
clean:
	rm -rf build/*.o build_test/*.o
