CXX := g++ -std=c++20
CPPFLAGS := -g

main: card.o


clean: 
	rm card.o main
