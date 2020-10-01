/*
* input:
*	K(base), n(number of digits), mod
*   number (all letters have to be in uppercase)
*/


#include <iostream>

int num_from_digit(char digit);

int main() {
	int base, n, mod;
	std::cin >> base >> n >> mod;

	std::string input;
	std::cin >> input;
	int current_mod = 0;
	for (char digit : input) {
		current_mod *= base;
		current_mod += num_from_digit(digit);
		current_mod %= mod;
	}
	std::cout << current_mod << '\n';
	return 0;
}

int num_from_digit(char digit) {
	if (digit - 'A' >= 0)
		return digit - 'A' + 10;
	else
		return digit - '0';
}
