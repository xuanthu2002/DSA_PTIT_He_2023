#include <iostream>

using namespace std;

int F[1001][1001];
int mod = 1e9 + 7;

void qhd() {
	for(int i = 0; i <= 1000; i++) {
		F[i][i] = 1;
		F[0][i] = 1;
	}
	for(int i = 1; i <= 1000; i++) {
		for(int j = i + 1; j <= 1000; j++) {
			if(i != j) {
				F[i][j] = F[i - 1][j - 1] + F[i][j - 1];
				F[i][j] %= mod;
			}
		}
	}
}

int main() {
	qhd();
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << F[k][n] << endl;
	}
	return 0;
}

