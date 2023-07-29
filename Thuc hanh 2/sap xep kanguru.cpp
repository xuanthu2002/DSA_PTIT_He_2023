#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		int l = 0, r = n / 2;
		int kq = 0;
		while(l < n / 2 && r < n) {
			if(a[l] >= a[r] * 2) {
				kq += 1;
				l += 1;
				r += 1;
			}
			else {
				kq += 1;
				r += 1;
			}
		}
		kq = kq + (n / 2 - l) + (n - r);
		cout << kq << endl;
	}
	return 0;
}

