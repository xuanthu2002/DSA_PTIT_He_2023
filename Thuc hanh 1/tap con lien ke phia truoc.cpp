#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[k + 1];
		a[0] = 0;
		for(int i = 1; i <= k; i++) cin >> a[i];
		int i = k;
		while(i >= 1 && a[i] == a[i - 1] + 1) {
			i -= 1;
		}
		a[i] -= 1;
		for(int j = i + 1; j <= k; j++) {
			a[j] = n - k + j;
		}
		for(int i = 1; i <= k; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}

