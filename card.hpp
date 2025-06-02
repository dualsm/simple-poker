#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
	private:
		char suit;
		int rank;
	public:
		Card(int rank, char suit);
		~Card();
		int get_rank();
		/* 
			Inputs: None
			Outputs: Int; 1 = Spade, 2 = Heart, 3 = Club, 4 = Diamond
			Notes: get_suit() % 2 for suit; 0 = Red, 1 = Black
		*/
		int get_suit(); 
		std::string get_card_text(); 
		void print_card();
};
#endif
