#include "high_scores_r.h"
#include <iostream>
#include <fstream>

int f_high_scores_r() {

	std::string high_scores_filename{ "high_scores.txt" };

	// Read the high score file and print all results

	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}
	//}

	return 0;
}