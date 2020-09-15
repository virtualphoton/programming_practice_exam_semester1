#include <iostream>

int main(){
	int k;
	std::cin >> k;
	long double sum = 0;
	long long int factorial = 1;
	for (int multiplier = 1; multiplier <= k; multiplier += 1){
		factorial *= multiplier;
		sum += 1.0/factorial;
	}
	std::cout << sum << '\n';
	return 0;
}
