#include "high_scores_w.h"
#include <iostream>
#include <fstream>

int f_high_scores_w(int attempts_count, const std::string& user_name) {

	std::string high_scores_filename{ "high_scores.txt" };

	// Write new high score to the records table

	std::ofstream out_file{ high_scores_filename, std::ios_base::app };
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;

	return 0;
}