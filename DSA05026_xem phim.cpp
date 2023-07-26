#include <iostream>
#include <cstring>

using namespace std;

int F[101][250001];

int qhd(int a[], int c, int n) {
	memset(F, 0, sizeof(F));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= c; j++) {
			F[i][j] = F[i - 1][j];
			if(j >= a[i]) {
				F[i][j] = max(F[i][j], F[i - 1][j - a[i]] + a[i]);
			}
		}
	}
	return F[n][c];
}

int main() {
	int c, n;
	cin >> c >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << qhd(a, c, n) << endl;
	return 0;
}

