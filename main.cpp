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
		auto color_vec = color_way.at(card->get_suit() % 2);
		color_vec->push_back(card);
		// add to rank vector
		// -1 index for corresponding card value
		std::vector<std::shared_ptr<Card>>* rank_vec_ptr;
		auto ace_vec0 = rank_way.at(0);
		auto ace_vec13 = rank_way.at(13);
		switch (card->get_rank()){
			case 14: // ace/
				ace_vec0->push_back(card);
				ace_vec13->push_back(card);
				break;
			case 13: // king 
				rank_vec_ptr = suit_way.at(12);
				rank_vec_ptr->push_back(card);
				break;
			case 12: // queen
				rank_vec_ptr = suit_way.at(11);
				rank_vec_ptr->push_back(card);
				break;
			case 11: // jack
				rank_vec_ptr = suit_way.at(10);
				rank_vec_ptr->push_back(card);
				break;
			case 10: // 10
				rank_vec_ptr = suit_way.at(9);
				rank_vec_ptr->push_back(card);
				break;
			case 9: // 9
				rank_vec_ptr = suit_way.at(8); 
				rank_vec_ptr->push_back(card);
				break;
			case 8: // 8 
				rank_vec_ptr = suit_way.at(7); 
				rank_vec_ptr->push_back(card);
				break;
			case 7: // 7
				rank_vec_ptr = suit_way.at(6);
				rank_vec_ptr->push_back(card);
				break;
			case 6: // 6
				rank_vec_ptr = suit_way.at(5);
				rank_vec_ptr->push_back(card);
				break;
			case 5: // 5 
				rank_vec_ptr = suit_way.at(4);
				rank_vec_ptr->push_back(card);
				break;
			case 4: // 4
				rank_vec_ptr = suit_way.at(3);
				rank_vec_ptr->push_back(card);
				break;
			case 3: // 3
				rank_vec_ptr = suit_way.at(2);
				rank_vec_ptr->push_back(card);
				break;
			case 2: // 2 
				rank_vec_ptr = suit_way.at(1);
				rank_vec_ptr->push_back(card);
				break;
		}
		// add to suit vector
		switch (card->get_suit()){
			case 'S':
				suit_vec
		}	
	}	
	
	return i;
}

