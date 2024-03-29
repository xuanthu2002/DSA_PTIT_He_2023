#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int x) {
	if(l <= r) {
		int m = (l + r) / 2;
		if(a[m] == x) return 1;
		if(a[m] > x) {
			return binarySearch(a, l, m - 1, x);
		}
		else {
			return binarySearch(a, m + 1, r, x);
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << binarySearch(a, 0, n, x) << endl;
	}
	return 0;
}

