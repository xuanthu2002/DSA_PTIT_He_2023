#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++) {
		int n;
		cin >> n;
		cout << "Test " << test << ": ";
		for(int i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) {
				int cnt = 0;
				while(n % i == 0) {
					n /= i;
					cnt += 1;
				}
				cout << i << "(" << cnt << ") ";
			}
		}
		if(n > 1) {
			cout << n << "(1)";
		}
		cout << endl;
	}
	return 0;
}

