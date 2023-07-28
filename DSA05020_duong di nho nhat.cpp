#include <iostream>

using namespace std;

int a[1001][1001], f[1001][1001], n, m;

int qhd() {
	f[0][0] = a[0][0];
	for(int i = 1; i < n; i++) {
		f[i][0] = f[i - 1][0] + a[i][0];
	}
	for(int i = 1; i < m; i++) {
		f[0][i] = f[0][i - 1] + a[0][i];
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + a[i][j];
		}
	}
	return f[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		cout << qhd() << endl;
	}
	return 0;
}

