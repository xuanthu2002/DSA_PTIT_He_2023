#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		long long kq = 0;
		for(int i = 0; i < n - 1; i++) {
			int j = upper_bound(a + i + 1, a + n, k + a[i] - 1) - a;
			kq += j - i - 1;
		}
		cout << kq << endl;
	}
	return 0;
}

