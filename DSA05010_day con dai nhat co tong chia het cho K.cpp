#include <iostream>
#include <cstring>

using namespace std;

int qhd(int a[], int n, int k) {
	int F[n + 1][k];
	memset(F, 0, sizeof(F));
	for(int i = 1; i < k; i++) F[1][i] = -1e9;
	F[1][a[1]] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			F[i][j] = max(F[i - 1][j], F[i - 1][(j - a[i] + k) % k] + 1);
		}
	}
	return F[n][0];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n + 1];
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] %= k;
		}
		cout << qhd(a, n, k) << endl;
	}
	return 0;
}

