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
		int hand_rank;
	public:
		/* each player gets a player score object each round */
		HandScore(std::vector<std::shared_ptr<Card>>& hand){
			this->hand = hand;
		};
		~HandScore() = default;
		int parse_hand();
		int score_four_of_a_kind();
		int score_full_house();
		int score_flush();
		int score_straight();
		int score_three_of_a_kind();
		int score_pair();
		int score_high_card();
		int calc_score();
		void debug_print_vectors();
};
#endif
