#include <iostream>

using namespace std;

int mod = 1e9 + 7;

int qhd(int n, int k) {
	int d[100001] = {0};
	d[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i - k; j < i; j++) {
			if(j >= 0) {
				d[i] += d[j] % mod;
				d[i] %= mod;
			}
		}
	}
	return d[n];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << qhd(n, k) << endl;
	}
	return 0;
}

