#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores_w.h"
#include "high_scores_r.h"

int f_check_value(int max_value) {

	//const int target_value = 54;
	int current_value = 0;
	bool not_win = true;
	int attempts_count = 0;
	int c_value = f_random_value(max_value);
	int hsc = 0;

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	//Ask for guess number  - current value
	std::cout << "Enter your guess: from 0 to " << max_value - 1 << std::endl;

	do {
		std::cin >> current_value;

		attempts_count += 1;

		if (std::cin.fail()) {
				std::cout << "Bad value!" << std::endl;
				return -1;
			break;
			}
		else if (current_value >= max_value) {
			std::cout << "please enter the number between 0 and " << max_value - 1 << std::endl;
			continue;
		}
		else if (current_value > c_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < c_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			f_high_scores_w(attempts_count, user_name);
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);
	
	std::cout << "Do you want to see the high score table? (1 - yes, 2 - quit)" << std::endl;

	std::cin >> hsc;

	if (hsc == 1) {
		f_high_scores_r();
	}
	else if (hsc != 2) {
		std::cout << "Wrong value has been entered - quitting!" << std::endl;
	}
		
	return 0;
}