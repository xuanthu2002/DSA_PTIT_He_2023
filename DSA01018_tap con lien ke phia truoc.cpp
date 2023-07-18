#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[k + 1];
		for(int i = 1; i <= k; i++) cin >> a[i];
		int i = k;
		a[0] = 0;
		while(i > 0 && a[i] == a[i - 1] + 1) {
			a[i] = n - k + i;
			i -= 1;
		}
		a[i] -= 1;
		if(i == -1) {
			for(int i = 1; i <= k; i++) {
				cout << a[i] << " ";
			}
		}
		else {
			for(int i = 1; i <= k; i++) cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

