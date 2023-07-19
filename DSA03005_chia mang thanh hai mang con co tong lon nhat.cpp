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
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n);
		int left = 0;
		k = min(k, n - k);
		for(int i = 0; i < k; i++) {
			left += a[i];
		}
		cout << (sum - 2 * left) << endl;
	}
	return 0;
}

