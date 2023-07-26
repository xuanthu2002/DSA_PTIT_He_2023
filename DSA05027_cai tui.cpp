#include <iostream>
#include <cstring>

using namespace std;

int F[1001][1001];

int qhd(int a[], int c[], int n, int v) {
	memset(F, 0, sizeof(F));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= v; j++) {
			F[i][j] = F[i - 1][j];
			if(j >= a[i]) {
				F[i][j] = max(F[i][j], F[i - 1][j - a[i]] + c[i]);
			}
		}
	}
	return F[n][v];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, v;
		cin >> n >> v;
		int a[n + 1], c[n + 1];
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> c[i];
		cout << qhd(a, c, n, v) << endl;
	}
	return 0;
}

