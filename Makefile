CXX := g++ -std=c++20
CPPFLAGS := -g

main: card.o

# card.o: card.cpp card.hpp
#	-c card.cpp -o card.o
clean: 
	rm card.o main
