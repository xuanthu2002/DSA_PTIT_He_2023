#include <iostream>

using namespace std;

void solve () {
	int n;
	cin >> n;
	int *a = new int [n];
	int ** b = new int * [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = new int [n];
	}
	int cnt = 0;
	for (int i = n - 2; i >= 0; i--) {
		bool flag = false;
		for (int j = 0; j <= i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag) {
			for (int x = cnt - 1; x >= 0; x--) {
				cout << "Buoc " << x + 1 << ": ";
				for (int y = 0; y < n; y++) {
					cout << b[x][y] << " ";
				}
					cout << endl;
			}
			return;
		}
		for (int k = 0; k < n; k++) {
			b[cnt][k] = a[k];
		}
		cnt ++;
	}
	delete [] a;
	delete [] b;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
