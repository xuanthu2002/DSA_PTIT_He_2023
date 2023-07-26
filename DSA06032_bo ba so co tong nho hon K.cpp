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
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n - 1; j++) {
				int index = lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
				kq += index - j - 1;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

