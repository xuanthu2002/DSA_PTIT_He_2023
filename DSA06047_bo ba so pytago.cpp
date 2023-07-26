#include <iostream>
#include <algorithm>

using namespace std;

bool solve(long long a[], int n) {
	sort(a, a + n);
	for(int i = n - 1; i >= 2; i--) {
		int l = 0, r = n - 1;
		while(l < r) {
			if(a[l] + a[r] == a[i]) {
				return true;
			}
			else if(a[l] + a[r] <= a[i]) {
				l += 1;
			}
			else {
				r -= 1;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] *= a[i];
		}
		if(solve(a, n)) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

