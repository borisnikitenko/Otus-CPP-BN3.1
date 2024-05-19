cmake_minimum_required(VERSION 3.5)

project(game)

add_executable(game
	game.cpp
	check_value.cpp
	check_value.h
	random_value.cpp
	random_value.h
	high_scores_w.cpp
	high_scores_w.h
	high_scores_r.cpp
	high_scores_r.h
)

# add_executable(
#	random_value
#	random_value.cpp
#)

#add_executable(
#	high_scores
#	high_scores.cpp
#)

#add_executable(argument
#	argument.cpp
#)

set_target_properties(game PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)