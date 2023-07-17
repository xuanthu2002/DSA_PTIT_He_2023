#include <iostream>
#include <algorithm>

using namespace std;

string solve(int a[], int n, int k) {
	for(int i = n - 1; i > 1; i--) {
		int l = 0, r = i - 1;
		while(l < r) {
			if(a[l] + a[r] == k - a[i]) {
				return "YES";
			}
			else if(a[l] + a[r] < k - a[i]) {
				l += 1;
			}
			else {
				r -= 1;
			}
		}
	}
	return "NO";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		cout << solve(a, n , k) << endl;
	}
	return 0;
}

