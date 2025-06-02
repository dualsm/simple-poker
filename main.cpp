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

	// Hand Parsing for scoring - Line 65 to X
	// Using a vector for each method of scoring (suit, color, rank)
	// Vector at indicies implements chaining easily (what if we have 4 3's? -- makes 4 of a kind easy)
	// For each hand type, iterate through the necessary list
	// Once we determined each basic type, then assign to greater types.

	// accessing each of xxxx_way with .at(idx) to check for scoring
	// 2 vec for color
	// 14 vec for rank, 0 = Ace, 1 = 2, ..., 12 = king, 13 = Ace (duplicate Ace @ 0, 13 for easy Straight identification (sliding iteration? end on idx 9 = Card 10)
	// 4 vec for suit
	std::vector<std::vector<std::shared_ptr<Card>>*> color_way(2, new (std::vector<std::shared_ptr<Card>>));
	std::vector<std::vector<std::shared_ptr<Card>>*> rank_way(14, new (std::vector<std::shared_ptr<Card>>));
	std::vector<std::vector<std::shared_ptr<Card>>*> suit_way(4, new (std::vector<std::shared_ptr<Card>>));

	// auto ace_vec = rank_way.at(0);
	// ace_vec->push_back(std::shared_ptr<Card>(new Card(14, 'H')));

	for (auto card : hand){
		// add to color vector
		card->print_card();
		int curr_suit = card->get_suit();
		int curr_rank = card->get_rank();

		auto color_vec = color_way.at(curr_suit % 2); // mod(2): 0 = black, 1 = red
		color_vec->push_back(card);
		// -1 index for corresponding card value
		if (curr_rank == 14){	// ace
			auto ace_vec0 = rank_way.at(0);
			auto ace_vec13 = rank_way.at(13);
			ace_vec0->push_back(card);
			ace_vec13->push_back(card);
		}
		else{			// any other card
			auto rank_vec_ptr = rank_way.at(card->get_rank() - 1);
			rank_vec_ptr->push_back(card);
		}
		// add to suit vector
		auto suit_vec_ptr = suit_way.at(curr_suit);
		suit_vec_ptr->push_back(card);	
	}	
	
	return i;
}

