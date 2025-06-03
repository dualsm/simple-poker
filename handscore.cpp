#include "handscore.hpp"
#include <iostream>

int HandScore::parse_hand(){
	// this->score_ways.at(0);
	// 0 black, 1 red
	
	for (auto card : this->hand){
		// add to color vector
		card->print_card();
		int curr_suit = card->get_suit();
		int curr_rank = card->get_rank();

		auto color_vec = this->score_vec.at(0).at(curr_suit % 2); // mod(2): 0 = black, 1 = red
		color_vec.push_back(card);
		// -1 index for corresponding card value
		if (curr_rank == 14){	// ace
			auto ace_vec0 = this->score_vec.at(2).at(0);
			auto ace_vec13 = this->score_vec.at(2).at(13);
			ace_vec0.push_back(card);
			ace_vec13.push_back(card);
		}
		else{			// any other card
			auto rank_vec_ptr = this->score_vec.at(2).at(card->get_rank() - 1);
			rank_vec_ptr.push_back(card);
		}
		// add to suit vector
		auto suit_vec_ptr = this->score_vec.at(1).at(curr_suit);
		suit_vec_ptr.push_back(card);	
	}	

	return 0;
}

void HandScore::debug_print_vectors(){
	
	std::cout << "debug_print_vectors()" << std::endl;
}
