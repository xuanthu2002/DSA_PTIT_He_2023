#include <iostream>
#include <algorithm>

using namespace std;

//0.06s
int floor(long long a[], int n, long long x) {
	int l = 0, r = n - 1;
	int kq = -2;
	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] <= x) {
			kq = m;
			l = m + 1;
		}
		else if(a[m] > x) {
			r = m - 1;
		}
	}
	return kq + 1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		long long x;
		cin >> n >> x;
//		long long a[n];
//		for(int i = 0; i < n; i++) cin >> a[i];
//		sort(a, a + n);
//		cout << floor(a, n, x) << endl;
		int floor = -1;
		long long tmp = -1e18;
		long long in;
		for(int i = 0; i < n; i++) {
			cin >> in;
			if(in <= x && in > tmp) {
				floor = i + 1;
			}
		}
		cout << floor << endl;
	}
	return 0;
}

