#include <iostream>
#include <vector>
#include <cmath>

#define not !
#define False false
#define True true

using namespace std;
vector<int> primes_before(double ceil);

int main(){
	int n;
	cin >> n;
	if (n < 2)
		return 0;
	cout << n << " = ";
	vector<int> primes = primes_before(sqrt(n));
	int length = primes.size();
	for (int i = 0; i < length; i += 1) {
		if (not (n % primes[i])) {
			cout << primes[i];
			n /= primes[i];
			i -= 1;
			if (n != 1)
				cout << '*';
			else
				break;
		}
	}
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