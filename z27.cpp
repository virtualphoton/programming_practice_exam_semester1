#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>

using std::vector;

vector<int> read_int_vector_from_line(int expected_length=1, int iterator_start_pos=0, int default_value = 0);
int min(int a, int b);

int main() {
	int n;
	scanf_s("%d", &n);

	vector<vector<int>> matrix(n+1);
	matrix[0] = vector<int>(n + 1, INT_MAX);
	matrix[0][1] = 0;
	for (int i = 1; i <= n; i += 1)
		matrix[i] = read_int_vector_from_line(n+1, 1, INT_MAX);

	for (int i = 1; i <= n; i += 1)
		for (int j = 1; j <= n; j += 1)
			matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1]);
	
	printf("%d\n", matrix[n][n]);
}

int min(int a, int b) {
	return a < b ? a : b;
}

//returns vector of int from cin
//	expected_length: if 0 then won't read, another, if > 0, then will return all numbers from string. default=1
//	iterator_start_pos <= expected_length. default=0
//	default_value - value by which vector will be filled. default=0
vector<int> read_int_vector_from_line(int expected_length, int iterator_start_pos, int default_value) {
	//need 'vector', 'sstream' and 'iostream' packages
	std::string line = "";
	//to counter bug with reading empty string after using cin. If expected length = 0, then we don't read input
	while (!line.length() and expected_length)
		std::getline(std::cin, line);
	std::stringstream iss(line);

	vector<int> arr(expected_length, default_value);
	int temp_input;

	int iterator = iterator_start_pos;
	while (iss >> temp_input)
		if (expected_length and iterator < expected_length) {
			arr[iterator] = temp_input;
			//no, I won't use arr[iterator++], because it's disgusting
			iterator += 1;
		}
		else
			arr.push_back(temp_input);
	return arr;
}