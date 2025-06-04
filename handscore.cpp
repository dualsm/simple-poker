#include "handscore.hpp"
#include <iostream>
#include <memory>
// testing - discovered was pushing to copies of vectors
void print_vector(std::vector<std::shared_ptr<Card>> vec){
	for (auto card : vec){
		card->print_card();
	}
}
// suit @ 1, rank @ 2
int HandScore::parse_hand(){
	
	for (auto card : this->hand){
		int curr_suit = card->get_suit();
		int curr_rank = card->get_rank();
			
		// add to color vector
		this->score_vec.at(0).at(curr_suit % 2).push_back(card); // mod(2): 0 = black, 1 = red
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
	int count = 1;
	// iterate all 3 score vectors {color, suit, hand}
	for (auto vec_ways : this->score_vec){
		
		if (vec_ways.size() == 2) continue;
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

int HandScore::score_flush(){
	int flush_val = 0;
	int cards_scored = 0;
	std::vector<std::string> debug_flush_type = {"score_flush(): Spade flush detected","score_flush(): Heart flush detected","score_flush(): Club flush detected", "score_flush(): Diamond flush detected"};
	// access suit_ways, and then the Spade, Heart, Club, Diamond 
	for (int i = 0; i < 4; i++){
		if (this->score_vec.at(1).at(i).size() < 5)
			continue;
		
		std::cout << debug_flush_type[i] << std::endl; // debug line
		
		// score based on rank vector by iterating backwards & check for suit
		for (int j = this->score_vec.at(2).size() - 1; j >= 0; --j){
			// grab card	
			if (cards_scored >= 5)
				break;
			for (auto card : this->score_vec.at(2).at(j)){
				if (card->get_suit() == i){
					cards_scored++;
					flush_val += card->get_rank();
					std::cout << "score_flush(): Live Flush Value: " << flush_val << std::endl;
				}
			}		
		}
	}
	
	return flush_val;
}
// 13 - 4 = 9, 10, 11, 12, 13
int HandScore::score_straight(){
		int straight_score = 0;
		// looking for 5 in a row. Start at top ace and iterate backwards
		// reset if missing a vector
		for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
			int cards_scored = 0;
			int curr_straight_score = 0;
			for (int j = i-4; (j <= i) && (j > 0); ++j){
				
				if (this->score_vec.at(2).at(j).size() >= 1){
					cards_scored++;			
					curr_straight_score += this->score_vec.at(2).at(j).at(0)->get_rank();
				}
			}
			if (cards_scored == 5){
				straight_score = curr_straight_score;
				std::cout << "score_straight(): Straight detected" << std::endl;
				std::cout << "score_straight(): End Straight Value: " << straight_score << std::endl;
			}	
		}		
		
		return straight_score;
	};
int HandScore::score_four_of_a_kind(){
	int four_oak_score = 0;
	for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
			
		if (this->score_vec.at(2).at(i).size() == 4){
			four_oak_score += this->score_vec.at(2).at(i).at(0)->get_rank() * 4;
			std::cout << "score_four_of_a_kind(): Four Of A Kind detected" << std::endl;
			std::cout << "score_four_of_a_kind(): Four Of A Kind Value: " << four_oak_score << std::endl;
		}	
	}		
	return four_oak_score;
};
int HandScore::score_full_house(){
	int full_house_score = 0;
	// two three of a kinds case... how do you choose which one is the pair? 
	// how can you take out the cards... maybe we pop from vectors after we take? 
	for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
			
		if (this->score_vec.at(2).at(i).size() == 3){
			full_house_score += this->score_vec.at(2).at(i).at(0)->get_rank() * 3;
			auto card1 = this->score_vec.at(2).at(i).at(0);
			auto card2 = this->score_vec.at(2).at(i).at(1);
			auto card3 = this->score_vec.at(2).at(i).at(2);
			this->score_vec.at(2).at(i).pop_back();
			this->score_vec.at(2).at(i).pop_back();
			this->score_vec.at(2).at(i).pop_back();
		
			int pair_score = 0;
			for (int j = this->score_vec.at(2).size() - 1; j >= 0; --j){
				
				if (this->score_vec.at(2).at(j).size() >= 2){
					pair_score += this->score_vec.at(2).at(j).at(0)->get_rank() * 2;
					full_house_score += pair_score;
					std::cout << "score_full_house(): Full House detected" << std::endl;
					std::cout << "score_full_house(): Full House Value: " << full_house_score << std::endl;
					return full_house_score;
				}
			}
			// full house not detected, replace popped values
			if (pair_score == 0){
				this->score_vec.at(2).at(i).push_back(card1);
				this->score_vec.at(2).at(i).push_back(card2);
				this->score_vec.at(2).at(i).push_back(card3);
			}	
		}		
	}
	
	return 0;
}
int HandScore::score_three_of_a_kind(){
	int three_oak_score = 0;
	// two three of a kinds case... how do you choose which one is the pair? 
	// how can you take out the cards... maybe we pop from vectors after we take? 
	for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
			
		if (this->score_vec.at(2).at(i).size() == 3){
			three_oak_score += this->score_vec.at(2).at(i).at(0)->get_rank() * 3;
			this->score_vec.at(2).at(i).pop_back();
			this->score_vec.at(2).at(i).pop_back();
			this->score_vec.at(2).at(i).pop_back();
			std::cout << "score_three_of_a_kind(): Three Of A Kind detected" << std::endl;
			std::cout << "score_three_of_a_kind(): Three Of A Kind Value: " << three_oak_score << std::endl;
		}	
	}		
	return three_oak_score;
};
int HandScore::score_pair(){
	int pair_score = 0;
	for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
			
		if (this->score_vec.at(2).at(i).size() >= 2){
			pair_score += this->score_vec.at(2).at(i).at(0)->get_rank() * 2;
			this->score_vec.at(2).at(i).pop_back();
			this->score_vec.at(2).at(i).pop_back();
			std::cout << "score_pair(): Pair detected" << std::endl;
			std::cout << "score_pair(): Pair Value: " << pair_score << std::endl;
		}	
	}
	return pair_score;

};

int HandScore::score_high_card(){
	int high_card = 0;
	for (int i = this->score_vec.at(2).size() - 1; i >= 0; --i){
		if (this->score_vec.at(2).at(i).size() >= 1){
			high_card = this->score_vec.at(2).at(i).at(0)->get_rank();
			std::cout << "score_high_card(): High Card detected" << std::endl;
			std::cout << "score_high_card(): High Card Value: " << high_card << std::endl;
			break;
		}
	}
	return high_card;
};

int HandScore::calc_score(){
	int total_score = 0;
	int flush_score = HandScore::score_flush();
	if (flush_score != 0){
		total_score += flush_score;
		// set rank as flush
	}	
	int straight_score = HandScore::score_straight();	
	if (straight_score != 0){
		total_score += straight_score;
		// set rank as straight
	} 
	if (straight_score != 0 && flush_score != 0){
		// straight flush, royal won't matter cuz we just compare hand values anyways
		int REPLACE_STRAIGHT_FLUSH;
		return total_score;
	}

	int four_oak_score = HandScore::score_four_of_a_kind();	
	if (four_oak_score != 0) {
		total_score += four_oak_score;
		// set rank as four_oak
		int REPLACE_FOUR_OAK;
		return total_score;
	}
	int full_house_score = HandScore::score_full_house();
	if (full_house_score != 0){
		total_score += full_house_score;
		int REPLACE_FULL_HOUSE;
		return total_score;
	}

	if (straight_score != 0 || flush_score != 0){
		// at this point, we can return the straight OR flush. straight flush detected earlier.
		return total_score;
	}

	int three_oak_score = HandScore::score_three_of_a_kind();	
	if (three_oak_score != 0){
		total_score += three_oak_score;
		// set rank as three_oak
		int REPLACE_THREE_OAK;
		return total_score;
	}
		
	int pair_score = HandScore::score_pair();
	if (pair_score != 0){
		total_score += pair_score;
		int REPLACE_PAIR;
		int two_pair_score = HandScore::score_pair();
		if (two_pair_score != 0){
			// set rank as two_pair
			int REPLACE_TWO_PAIR;
		}
		return total_score;
	}
/*	int high_card_score = HandScore::score_high_card();
	int REPLACE_HIGH_CARD;
	total_score += high_card_score;
*/	
	return total_score;
};
