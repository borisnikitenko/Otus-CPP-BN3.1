#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores_w.h"
#include "high_scores_r.h"
#include "check_value.h"


int main(int argc, char** argv) {

	int max_value(100);
	int level_value(3);
	int current_value = 0;
	bool not_win = true;
	int attempts_count = 0;
	int hsc = 0;

	if (argc == 3) {
		

		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {


			// We've detected the '-max' argument. And we extect that after this argument there is a value:
			//int max_v = 0;
						
			// We need to parse the string to the int value
			max_value = std::stoi(argv[2]);

			// Here we need to pass this max value into check scores func, probably check the range (100 - max)
			f_check_value(max_value);
			return 0;
		}
		else if (arg1_value == "-level") {
		//Here we need to run check value with level option 1,2,3, ensure only 1,2 or 3 values have been entered
			level_value = std::stoi(argv[2]);
				switch (level_value) 
				{
				case 1:
					max_value = 10;
					//call check scores with 10 max value
					break;
				case 2:
					max_value = 50;
					//call check scores with 50 max value
					break;
				case 3:
					max_value = 100;
					//call check scores with 100 max value
					break;
				default:
					std::cout << "Wrong value has been entered - quitting!" << std::endl;
					return -1;
					break;
				}
			f_check_value(max_value);
			return 0;
		}
		else {
			std::cout << "Unknown parameter has been entered - quitting!" << std::endl;
			return -1;
		}
		}
	else if (argc == 1) {
	//Here we need to run check scores with default params - i.e. random value func result with 100 max, since no arguments have been entered
		f_check_value(max_value);
		return 0;
	}
	else if (argc == 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-table") {
		//just show the high scores table and quit the program
		  f_high_scores_r();
		  return 0;
		}
		else {
			std::cout << "Wrong usage! Expect only these arguments and their values: -max (required val up to 100) or -level (required vals: 1,2 or 3) or -table (without values)" << std::endl;
			return -1;
		}
	}
	else {
		std::cout << "Wrong usage! Expect only these arguments and their values: -max (required val up to 100) or -level (required vals: 1,2 or 3) or -table (without values)" << std::endl;
		return -1;
	}
}

