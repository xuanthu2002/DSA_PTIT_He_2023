#include <iostream>
#include <cstring>

using namespace std;

int F[1001][1001], A[1001], C[1001], n , v;

int qhd() {
	memset(F, 0, sizeof(F));
	int kq = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= v; j++) {
			F[i][j] = F[i - 1][j];
			if(j >= A[i]) {
				F[i][j] = max(F[i][j], F[i - 1][j - A[i]] + C[i]);
			}
		}
	}
	return F[n][v];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> v;
		for(int i = 1; i <= n; i++) cin >> A[i];
		for(int i = 1; i <= n; i++) cin >> C[i];
		cout << qhd() << endl;
	}
	return 0;
}

