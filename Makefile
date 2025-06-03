CXX := g++ -std=c++20
CPPFLAGS := -g

main: card.o handscore.o


clean: 
	rm handscore.o card.o main
