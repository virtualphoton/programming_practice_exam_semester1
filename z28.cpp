#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> primes_not_exceed(double ceil);

int main(){
	int n;
	cin >> n;
	if (n < 2)
		return 0;
	cout << n << " = ";
	vector<int> primes = primes_not_exceed(sqrt(n));
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
	if (n != 1)
		cout << n;
	cout << '\n';

	return 0;
}


//vector of all prime numbers <= ceil 
vector<int> primes_not_exceed(double ceil) {
	vector<int> primes;
	for (int test_prime = 2; test_prime <= ceil; test_prime += 1) {
		bool is_not_prime = false;
		for (int prime : primes)
			if (not (test_prime % prime)) {
				is_not_prime = true;
				break;
			}
		if (not is_not_prime)
			primes.push_back(test_prime);
	}
	return primes;
}
