.default: all

all: week01_example

clean:
	rm -f assign1 *.o

week01_example: Env.o week01_main.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^