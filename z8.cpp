#include <iostream>
#include <string>

using namespace std;
void recur_deeper(string output, int depth, int max_depth, int output_length) {
	//border cases
	{
		if (depth == 0)
			output = "{";

		if (depth == max_depth) {
			//delete last comma
			if (output_length)
				output = output.substr(0, output.length() - 2);

			output = output.append("}");
			cout << output << '\n';
			return;
		}
	}
	//do recursion
	{

		//not include
		recur_deeper(output, depth + 1, max_depth, output_length + 1);

		//include current element
		output = output.append(to_string(depth).append(", "));
		recur_deeper(output, depth + 1, max_depth, output_length + 1);

	}

}

int main() {
	int n;
	cin >> n;
	recur_deeper("", 0, n, 0);
	return 0;
}