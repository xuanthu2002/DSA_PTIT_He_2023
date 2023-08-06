#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long res = 0;
	while(n--) {
		int x;
		cin >> x;
		if(x > 0) {
			res += x * 2;
		}
	}
	cout << res;
	return 0;
}

