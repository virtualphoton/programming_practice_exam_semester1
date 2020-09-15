#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;
	int current_mod = 0;
	for (auto digit : input) {
		current_mod *= 2;
		if (digit == '1')
			current_mod += 1;
		current_mod %= 15;
	}
	cout << ((current_mod) ? "NO" : "YES") << '\n';
}
