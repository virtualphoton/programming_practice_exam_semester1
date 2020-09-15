/*
* input:
*	K(base), n(number of digits), mod
*   number
*/


#include <iostream>
using namespace std;

int num_from_digit(char digit);

int main() {
	int base, n, mod;
	cin >> base >> n >> mod;

	string input;
	cin >> input;
	int current_mod = 0;
	for (char digit : input) {
		current_mod *= base;
		current_mod += num_from_digit(digit);
		current_mod %= mod;
	}
	cout << current_mod << endl;
}

int num_from_digit(char digit) {
	if (digit - 'A' >= 0)
		return digit - 'A' + 10;
	else
		return digit - '0';
}