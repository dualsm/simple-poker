#include <vector>
#include <iostream> 
#include <memory>
#include <string>
#include "card.hpp"
/* 
	Class List: 
	- {Deck, Hand, Card, Player}
	Class structure: 
	- Deck has an array of Cards
	- Player has a Hand
	- Hand has Cards
	- Table has array of Players, shared Cards, and a Deck

*/

/* 
	Rank: 
	- 0=Ace,2,3,4,5,6,7,8,9,10,11=Jack,12=Queen,13=King
	Suit:
	- Red suits are even, H = 2 Heart, D = 4 Diamond
	- Black suits are odd, S = 1 Spade, C = 3 Club
*/


// class Card {
// 	private:
// 		char suit;
// 		int rank;
// 	public:
// 		Card(int rank, char suit){
// 			this->suit = suit;
// 			this->rank = rank;
// 			std::cout << "Card constructor called on [" << this->suit << " " << this->rank << "]" << std::endl;
// 		};
// 		~Card(){
// 			std::cout << "Card destructor called on [" << this->suit << " " << this->rank << "]" << std::endl;
// 		};
// 		int get_rank(){
// 			return this->rank;
// 		}; 
// 		/* 
// 			Inputs: None
// 			Outputs: Int; 1 = Spade, 2 = Heart, 3 = Club, 4 = Diamond
// 			Notes: get_suit() % 2 for suit; 0 = Red, 1 = Black
// 		*/
// 		int get_suit(){
// 			int out_suit;
// 			switch (this->suit){
// 				case 'S':
// 					out_suit = 1;
// 					break;	
// 				case 'H':
// 					out_suit = 2;
// 					break;	
// 				case 'C':
// 					out_suit = 3;
// 					break;	
// 				case 'D':
// 					out_suit = 4;
// 					break;	
// 			}
// 			return out_suit;
// 		}; 
// 
// 		std::string print_card(){
// 			// fill constructor
// 			char format[7];
// 			char p_rank[2];
// 			switch (this->rank){
// 				case 1:
// 					strncpy(p_rank, "A\0", 2);
// 					break;
// 				case 13:
// 					strncpy(p_rank, "K\0", 2);
// 					break;
// 				case 12:
// 					strncpy(p_rank, "Q\0", 2);
// 					break;
// 				case 11:
// 					strncpy(p_rank, "J\0", 2);
// 					break;
// 				default:
// 					
// 					snprintf(p_rank,2, "%d", this->rank);	
// 					break;
// 			}	
// 			// format << "[" << this->suit << " " << p_rank << "]";	
// 			// return std::format("[{} {:2f}]", this->suit, p_rank);
// 			snprintf(format, 7, "[%-2s %1s]",  p_rank, &this->suit);
// 			return format;
// 		}; 
// 		
// };


int main() {
	int i = 1;
	std::string hello = "hello world";
	std::cout << hello << std::endl;
	// OK for initialization
	// 	std::shared_ptr<Card> nine_hearts(new Card(9, 'H'));
	// Preferred for initialization? (more readable imo)
	// 	auto four_spades = std::make_shared<Card>(4, 'S');
	// Trash cause I have to manage my own memory with calls to delete later
	//	Card* ace_diamonds = new Card(0, 'D');
	
	
	// 0, 1... 14, 15
	// 2 3 4 5 6 7 8 9 10 J Q K == 12 numbers


	// make full deck & print full deck
	// array of shared ptrs?
	std::vector<std::shared_ptr<Card>> deck;
	char suits[4] = {'S', 'H', 'C', 'D'};
	for (int i = 0; i < 4; i++){
		for (int j = 1; j <= 13; j++)
			deck.push_back(std::shared_ptr<Card> (new Card(j, suits[i])));
	}	

	while (!deck.empty()){
		auto temp = deck.back();
		deck.pop_back();
		temp->print_card();
	}	
	return i;
}

