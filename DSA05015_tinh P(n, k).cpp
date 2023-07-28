#include <iostream>

using namespace std;

int M = 1e9 + 7;

long long P(int n, int k) {
	if(k > n) {
		return 0;
	}
	long long p = 1;
	for(int i = n - k + 1; i <= n; i++) {
		p *= i;
		p %= M;
	}
	return p;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << P(n, k) << endl;
	}
	return 0;
}
