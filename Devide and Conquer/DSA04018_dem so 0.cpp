#include <iostream>

using namespace std;

int lastIndexOf(int a[], int n, int x) {
	int l = 0, r = n - 1;
	int res = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] == x) {
			res = m;
			l = m + 1;
		}
		else if(a[m] > x) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int kq = lastIndexOf(a, n, 0);
		cout << kq + 1 << endl;
	}
	return 0;
}

