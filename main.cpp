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
	- 1 = Ace,2,3,4,5,6,7,8,9,10,11=Jack,12=Queen,13=King
	Suit:
	- Red suits are even, H = 2 Heart, D = 4 Diamond
	- Black suits are odd, S = 1 Spade, C = 3 Club
*/

int main() {

	srand(0);	
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
		for (int j = 2; j <= 14; j++)
			deck.push_back(std::shared_ptr<Card> (new Card(j, suits[i])));
	}	
	std::cout << "Is deck empty? " << deck.empty()  << std::endl;
//	while (1 != deck.empty()){
//		auto temp = deck.back();
//		temp->print_card(); 
//		deck.pop_back();
//	}
	std::vector<std::shared_ptr<Card>> hand; 
	// Create a hand of 5 cards, popping from deck
	for (int i = 0; i < 5; i++){
		int psuedo_rand = rand() % deck.size(); //will always be in range
		hand.push_back(deck.at(psuedo_rand));
		deck.erase(deck.begin() + psuedo_rand); 
	}
	std::vector<std::vector<std::shared_ptr<Card>>* > color_way;
	std::vector<std::vector<std::shared_ptr<Card>>* > rank_way;
	std::vector<std::vector<std::shared_ptr<Card>>* > suit_way;

	std::vector<std::vector<std::shared_ptr<Card>>* > vector2 (13, new std::vector<std::shared_ptr<Card>>);

	
	// init the vectors
	// 2 vec for color
	color_way.push_back(new std::vector<std::shared_ptr<Card>>);
	color_way.push_back(new std::vector<std::shared_ptr<Card>>);
	// 4 vec for suit
	rank_way.push_back(new std::vector<std::shared_ptr<Card>>);
	rank_way.push_back(new std::vector<std::shared_ptr<Card>>);
	rank_way.push_back(new std::vector<std::shared_ptr<Card>>);
	rank_way.push_back(new std::vector<std::shared_ptr<Card>>);
	// 13 vec for rank (2 off error!) idx 0 = 2; idx 12 = 14 (Ace)
	for (int i = 0; i < 13; i++) rank_way.push_back(new std::vector<std::shared_ptr<Card>>);


	for (auto card : hand){
		card->print_card();
		if (card->get_suit() % 2 == 0){
			auto black_vec = color_way.at(0);
		}
	}
	// SHCD, get_suit() % 2 = 0 for red, 1 for black?

	
	return i;
}

