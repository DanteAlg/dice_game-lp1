#ifndef _DICE_H_
#define _DICE_H_

#include <random>

class Dice {
	private:
		int value;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;

	public:
		Dice ();
		int roll();
		int getValue();
};

#endif
