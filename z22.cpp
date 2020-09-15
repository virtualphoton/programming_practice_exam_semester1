/*input:
	N, needed_sum
	A1, ..., AN
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int sign_recurs(vector<int> numbers, int sum, int depth, int needed_sum, vector<int>& signs);


int main() {
	ifstream input;
	input.open("in.txt");
	int n, needed_sum;
	input >> n >> needed_sum;
	vector<int> numbers(n);
	for (int i = 0; i < n; i += 1)
		input >> numbers[i];
	input.close();

	vector<int> signs(n);
	ofstream output;
	output.open("out.txt");

	if (sign_recurs(numbers, 0, 0, needed_sum, signs)) {
		output << numbers[0];
		for (int i = 1; i < n; i += 1) {
			output << ((signs[i] == 1) ? " + " : " - ") << numbers[i];
		}
	}

	output.close();
}

int sign_recurs(vector<int> numbers, int sum, int depth, int needed_sum, vector<int>& signs) {

	if (depth == numbers.size())
		return 0;

	{

		signs[depth] = 1;

		if (sum + numbers[depth] == needed_sum or
			sign_recurs(numbers, sum + numbers[depth], depth + 1, needed_sum, signs) == 1)
			return 1;

		if (depth == 0)
			return 0;


		signs[depth] = -1;
		if (sum - numbers[depth] == needed_sum or
			sign_recurs(numbers, sum - numbers[depth], depth + 1, needed_sum, signs) == 1)
			return 1;

		return 0;
	}
}