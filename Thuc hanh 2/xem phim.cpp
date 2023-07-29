#include <iostream>
#include <cstring>

using namespace std;

int F[101][25001];

int qhd(int a[], int n, int c) {
	memset(F, 0, sizeof(F));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= c; j++) {
			F[i][j] = F[i - 1][j];
			if(j > a[i - 1]) {
				F[i][j] = max(F[i][j], F[i - 1][j - a[i - 1]] + a[i - 1]);
			}
		}
	}
	return F[n][c];
}

int main() {
	int c, n;
	cin >> c >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << qhd(a, n, c);
	return 0;
}

