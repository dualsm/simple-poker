#include "card.hpp"

#include <iostream>

Card::Card(int rank, char suit){
	this->suit = suit;
	this->rank = rank;
	std::cout << "Card constructor called on [" << this->suit << " " << this->rank << "]" << std::endl;
};

Card::~Card(){
	std::cout << "Card destructor called on [" << this->suit << " " << this->rank << "]" << std::endl;
};

int Card::get_rank(){
	return this->rank;
}; 

/* 
	Inputs: None
	Outputs: Int; 1 = Spade, 2 = Heart, 3 = Club, 4 = Diamond
	Notes: get_suit() % 2 for suit; 0 = Red, 1 = Black
*/
int Card::get_suit(){
	int out_suit;
	switch (this->suit){
		case 'S':
			out_suit = 1;
			break;	
		case 'H':
			out_suit = 2;
				break;	
		case 'C':
			out_suit = 3;
			break;	
		case 'D':
			out_suit = 4;
			break;	
	}
	return out_suit;
}; 

std::string Card::print_card(){
	// fill constructor
	char format[7];
	char p_rank[2];
	switch (this->rank){
		case 1:
			strncpy(p_rank, "A\0", 2);
			break;
		case 13:
			strncpy(p_rank, "K\0", 2);
			break;
		case 12:
			strncpy(p_rank, "Q\0", 2);
			break;
		case 11:
			strncpy(p_rank, "J\0", 2);
			break;
		default:
			snprintf(p_rank,2, "%d", this->rank);	
			break;
		}	
	snprintf(format, 7, "[%-2s %1s]",  p_rank, &this->suit);
	return format;
}; 
