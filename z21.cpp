#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#define not !
#define False false
#define True true
#define in :

using namespace std;
vector<int> primes_before(double ceil);

int main() {
	int a, b;

	ifstream input;
	input.open("in.txt");
	input >> a >> b;
	input.close();

	vector<int> primes = primes_before(b);
	
	ofstream output;
	output.open("out.txt");
	for (int prime in primes)
		if (prime >= a)
			output << prime << ' ';

}


//vector of all prime numbers <= ceil 
vector<int> primes_before(double ceil) {
	vector<int> primes;
	for (int test_prime = 2; test_prime <= ceil; test_prime += 1) {
		bool is_not_prime = False;
		for (int prime : primes)
			if (not (test_prime % prime)) {
				is_not_prime = True;
				break;
			}
		if (not is_not_prime)
			primes.push_back(test_prime);
	}
	return primes;
}