CFLAGS = -std=c++23 -Wall -Wextra -Wpedantic
LDFLAGS = -lglfw -lGL

engine: *.cpp *.hpp
	g++ $(CFLAGS) -o engine *.c *.cpp $(LDFLAGS)

.PHONY: test clean

test: engine
	./engine

clean:
	rm -f engine
