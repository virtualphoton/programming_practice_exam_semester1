#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;
vector<int> primes_not_exceeding(double ceil);

int main() {
	int a, b;

	ifstream input;
	input.open("in.txt");
	input >> a >> b;
	input.close();

	vector<int> primes = primes_not_exceeding(b);
	
	ofstream output;
	output.open("out.txt");
	for (int prime : primes)
		if (prime >= a)
			output << prime << ' ';
	output.close();
	return 0;
}


//vector of all prime numbers <= ceil 
vector<int> primes_not_exceeding(double ceil) {
	vector<int> primes;
	for (int test_prime = 2; test_prime <= ceil; test_prime += 1) {
		bool is_not_prime = false;
		for (int prime : primes)
			if (not (test_prime % prime)) {
				is_not_prime = true;
				break;
			}
		if (!is_not_prime)
			primes.push_back(test_prime);
	}
	return primes;
}
