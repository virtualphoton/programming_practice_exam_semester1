#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int global_iter = 1;
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			cout << global_iter << '\t';
			global_iter += 1;
		}
		cout << '\n';
	}

	return 0;
}
