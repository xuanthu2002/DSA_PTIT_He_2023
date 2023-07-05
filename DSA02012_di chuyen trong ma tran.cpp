#include <iostream>
#include <cstring>

using namespace std;

int a[101][101];

int main() {
	memset(a, 0, sizeof(a));
	for(int i = 0; i <= 100; i++) {
		a[i][0] = 1;
		a[0][i] = 1;
	}
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			a[i][j] += (a[i - 1][j] + a[i][j - 1]);
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				cin >> x;
			}
		}
		cout << a[n - 1][m - 1] << endl;
	}
	return 0;
}

