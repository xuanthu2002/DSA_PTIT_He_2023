#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[k + 1];
		a[k] = n;
		for(int i = 0; i < k; i++) {
			cin >> a[i];
		}
		int i = k - 1;
		while(i >= 0 && a[i] == n - k + i + 1) {
			i -= 1;
		}
		if(i < 0) cout << k << endl;
		else cout << a[i + 1] - a[i] << endl;
	}
	return 0;
}

