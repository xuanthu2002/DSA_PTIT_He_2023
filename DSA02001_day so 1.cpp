#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		a[n] = 0;
		for(int i = 0; i < n; i++) {
			cout << "[";
			for(int j = 0; j < n - i - 1; j++) {
				cout << a[j] << " ";
				a[j] += a[j + 1];
			}
			cout << a[n - i - 1] << "]" << endl;
			a[n - i - 1] += a[n - i];
		}
	}
	return 0;
}

