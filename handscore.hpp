#ifndef HANDSCORE_HPP 
#define HANDSCORE_HPP
#include <string>
#include <vector>
#include <memory>
#include "card.hpp"
class HandScore{
	private:
		std::vector<std::vector<std::vector<std::shared_ptr<Card>>>> score_vec {
			std::vector<std::vector<std::shared_ptr<Card>>>(2),
			std::vector<std::vector<std::shared_ptr<Card>>>(4),
			std::vector<std::vector<std::shared_ptr<Card>>>(14)
		};
		std::vector<std::shared_ptr<Card>> hand;
		int total_score = 0;
	public:
		/* each player gets a player score object each round */
		HandScore(std::vector<std::shared_ptr<Card>>& hand){
			this->hand = hand;
		};
		~HandScore() = default;
		int parse_hand();
		int score_flush(){return 1;};
		int score_straight(){return 1;};
		int score_four_of_a_kind(){return 1;};
		int score_three_of_a_kind(){return 1;};
		int score_two_pair(){return 1;};
		int score_pair(){return 1;};
		int score_high_card(){return 1;};
		int calc_score(){return 1;};
		void debug_print_vectors();
};
#endif
