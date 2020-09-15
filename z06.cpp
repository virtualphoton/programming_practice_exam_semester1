#include <iostream>

using namespace std;

int main(){
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i+=1){
		cin >> a;
		cout << ((a >= n or a < 0) ? "NO":"YES") << endl;
	}
	return 0;
}
