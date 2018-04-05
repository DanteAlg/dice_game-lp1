#include <random>

#include "dice.h"

Dice::Dice():rd(), gen(rd()), dis(1, 6) {
	value = std::round(dis(gen));
}

int Dice::roll() {
	value = std::round(dis(gen));
	return value;
}

int Dice::getValue() {
	return value;
}
