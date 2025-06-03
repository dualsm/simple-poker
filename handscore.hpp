#ifndef HANDSCORE_HPP 
#define HANDSCORE_HPP
#include <string>
#include <vector>
#include "card.hpp"
class HandScore{
	private:
		std::vector<std::vector<std::vector<std::shared_ptr<Card>>>> score_vec {
			std::vector<std::vector<std::shared_ptr<Card>>>(2),
			std::vector<std::vector<std::shared_ptr<Card>>>(4),
			std::vector<std::vector<std::shared_ptr<Card>>>(14)
		};
			
		int total_score = 0;
	public:
		/* each player gets a player score object each round */
		HandScore() = default;
		~HandScore();
		int parse_hand();
		void debug_print_vectors();
};
#endif
