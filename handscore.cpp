#include "handscore.hpp"
#include <iostream>
#include <memory>
// testing - discovered was pushing to copies of vectors
void print_vector(std::vector<std::shared_ptr<Card>> vec){
	for (auto card : vec){
		card->print_card();
	}
}

int HandScore::parse_hand(){
	// this->score_ways.at(0);
	// 0 black, 1 red
	
	for (auto card : this->hand){
		card->print_card();
		int curr_suit = card->get_suit();
		int curr_rank = card->get_rank();
			
		// add to color vector
		this->score_vec.at(0).at(curr_suit % 2).push_back(card); // mod(2): 0 = black, 1 = red
		print_vector(this->score_vec.at(0).at(curr_suit % 2));
		// -1 index for corresponding card value
		if (curr_rank == 14){	// ace
			this->score_vec.at(2).at(0).push_back(card);
			this->score_vec.at(2).at(13).push_back(card);
		}
		else{			// any other card
			this->score_vec.at(2).at(card->get_rank() - 1).push_back(card);
		}
		// add to suit vector
		this->score_vec.at(1).at(curr_suit).push_back(card);
	}	

	return 0;
}

void HandScore::debug_print_vectors(){
	
	std::cout << "debug_print_vectors()" << std::endl;
	int count = 0;
	// iterate all 3 score vectors {color, suit, hand}
	for (auto vec_ways : this->score_vec){
		std::cout << "Ways Vector #" << count << std::endl;
		count++;
		// access the vectors within the 3 score vectors {black, red; S,H,C,D; 0..14}
		for (auto vec_idx : vec_ways){ 
			// access the vectors 
			for (auto card : vec_idx){
				card->print_card();
			}
		}
	}
}
