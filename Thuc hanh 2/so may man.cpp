#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt4 = 0, cnt7 = 0;
		while(n % 7 != 0 && n >= 4) {
			cnt4 += 1;
			n -= 4;
		}
		if(n % 7 != 0) {
			cout << -1 << endl;
		}
		else {
			cnt7 = n / 7;
			while(cnt4--) cout << 4;
			while(cnt7--) cout << 7;
			cout << endl;
		}
	}
	return 0;
}

