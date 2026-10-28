# Build with `make`, run with `make run`, clean up with `make clean`.
CXX ?= g++
FLAGS ?= -std=c++17 -Wall -Wextra -g

main: main.cpp
	$(CXX) $(FLAGS) main.cpp -o main

run: main
	./main

clean:
	rm -f main main.exe

.PHONY: run clean
