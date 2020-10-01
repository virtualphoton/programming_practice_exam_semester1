#include <iostream>

int main() {
	std::string input;
	std::cin >> input;
	int current_mod = 0;
	for (auto digit : input) {
		current_mod *= 2;
		if (digit == '1')
			current_mod += 1;
		current_mod %= 15;
	}
	std::cout << ((current_mod) ? "NO" : "YES") << '\n';
	return 0;
}
