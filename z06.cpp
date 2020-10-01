#include <iostream>

int main(){
	int n, a;
	std::cin >> n;
	for (int i = 0; i < n; i+=1){
		std::cin >> a;
		std::cout << ((a >= n or a < 0) ? "NO":"YES") << '\n';
	}
	return 0;
}
