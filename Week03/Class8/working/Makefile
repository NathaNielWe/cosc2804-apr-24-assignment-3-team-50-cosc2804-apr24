.default: all

all: class8_example

clean:
	rm -f class8_example *.o

class8_example: Field.o main.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^