CFLAGS = -std=c++23 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wdouble-promotion -Wnull-dereference
LDFLAGS = -lglfw -lGL

engine: *.cpp *.hpp
	g++ $(CFLAGS) -o engine *.c *.cpp $(LDFLAGS)

.PHONY: test clean

test: engine
	./engine

clean:
	rm -f engine
