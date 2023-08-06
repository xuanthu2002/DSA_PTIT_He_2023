#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int d[k + 1] = {0};
		d[0] = 1;
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < n; j++) {
				if(i >= a[j]) {
					d[i] = (long long) (d[i] + d[i - a[j]]) % mod;
					d[i] %= mod;
				}
			}
		}
		cout << d[k] << endl;
	}
	return 0;
}

