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


int lastIndexOf(int a[], int l, int r, int x) {
	if(l <= r) {
		int m = (l + r) / 2;
		if(a[m] == x) {
			return max(m, lastIndexOf(a, m + 1, r, x));
		}
		else if(a[m] > x) {
			return lastIndexOf(a, l, m - 1, x);
		}
		else {
			return lastIndexOf(a, m + 1, r, x);
		}
	}
	return -1;
} 

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
//		int kq = lastIndexOf(a, n, 0);
		int kq = lastIndexOf(a, 0, n - 1, 0);
		cout << kq + 1 << endl;
	}
	return 0;
}

