#include <vector>
#include <iostream> 
#include <memory>
#include <string>
#include "card.hpp"
#include "handscore.hpp"
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
	- 0=Ace, 1=2, ..., 12=King, 13=Ace

*/
// score_ways = {color, suit, rank}

// Create a hand of 5 cards, popping from deck
std::vector<std::shared_ptr<Card>> create_hand(std::vector<std::shared_ptr<Card>> &deck) {
	std::vector<std::shared_ptr<Card>> hand;
	for (int i = 0; i < 5; i++){
		int psuedo_rand = rand() % deck.size(); //will always be in range
		hand.push_back(deck.at(psuedo_rand));
		deck.erase(deck.begin() + psuedo_rand); 
	}
	return hand;
}

int main() {

	srand(time(0));	
	int i = 1;

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
	std::vector<std::shared_ptr<Card>> hand = create_hand(deck); 

	// Hand Parsing for scoring - Line 65 to X
	// Using a vector for each method of scoring (suit, color, rank)
	// Vector at indicies implements chaining easily (what if we have 4 3's? -- makes 4 of a kind easy)
	// For each hand type, iterate through the necessary list
	// Once we determined each basic type, then assign to greater types.
	HandScore HandScoreObj(hand);

	int parse_result = HandScoreObj.parse_hand();	
	if (parse_result != 0) std::cout << "ERROR: parse_hand()" << std::endl;
	else { std::cout << "SUCCESS: parse_hand()" << std::endl; }

	HandScoreObj.debug_print_vectors();
	
	return i;
}

