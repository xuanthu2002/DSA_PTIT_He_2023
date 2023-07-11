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
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int l = 0, r = n - 1;
		while(l < r) {
			cout << a[r] << " " << a[l] << " ";
			l += 1;
			r -= 1;
		}
		if(n & 1) {
			cout << a[l];
		}
		cout << endl;
	}
	return 0;
}

