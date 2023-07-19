#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int mod = 1e9 + 7;
		long long kq = 0;
		for(int i = 0; i < n; i++) {
			kq += (long long) a[i] * i % mod;
			kq %= mod;
		}
		cout << kq << endl;
	}
	return 0;
}


