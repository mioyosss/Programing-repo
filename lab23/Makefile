targets = main.bin test.bin
CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/lib.cpp 

all: run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@ -lm

test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: compile
	./dist/main.bin
test: clean prep compile
	./dist/test.bin
	
doxygen: prep
	doxygen Doxyfile
format: #TODO

tidy: # TODO

