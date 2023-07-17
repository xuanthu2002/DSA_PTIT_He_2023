#include <iostream>

using namespace std;

int F[28];

int fibonacciSearch(int a[], int l, int r, int x) {
	if(l <= r) {
		int i = 0;
		while(F[i] < (r - l)) {
			i += 1;
		}
		int m = l + i;
		if(a[m] == x) {
			return m + 1;
		}
		else if(a[m] > x) {
			return fibonacciSearch(a, l, m - 1, x);
		}
		else {
			return fibonacciSearch(a, m + 1, r, x);
		}	
	}
	return -1;
}

int main() {
	F[0] = 1;
	F[1] = 1;
	for(int i = 2; i < 27; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int kq = fibonacciSearch(a, 0, n, x);
		if(kq == -1) {
			cout << "NO" << endl;
		}
		else cout << kq << endl;
	}
	return 0;
}

