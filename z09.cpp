#include <iostream>
#include <string>

void recur_deeper(std::string output, int depth, int max_depth, int output_length, int length_to_stop) {

	//border cases
	//break if can't get enough numbers
	int steps_before_stop = length_to_stop - output_length;
	if (max_depth - depth < steps_before_stop)
		return;
	if (depth == 1)
		output = "{";
	//break if reach certain
	if (depth == max_depth or !steps_before_stop) {
		//delete last comma
		if (output_length)
			output = output.substr(0, output.length() - 2);
		output = output.append("}");
		std::cout << output << '\n';
		return;
	}

	//do recursion

	//not include
	recur_deeper(output, depth + 1, max_depth, output_length, length_to_stop);

	//include current element
	output = output.append(std::to_string(depth).append(", "));
	recur_deeper(output, depth + 1, max_depth, output_length + 1, length_to_stop);
}

int main() {
	int n, k;
	std::cin >> n;
	std::cin >> k;
	recur_deeper("", 1, n+1, 0, k);
	return 0;
}
