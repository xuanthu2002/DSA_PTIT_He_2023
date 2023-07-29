#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
int F[101][50001];

void qhd() {
	for(int i = 0; i < 10; i++) F[1][i] = 1;
	for(int i = 2; i < 101; i++) {
		for(int j = 0; j < 50001; j++) {
			F[i][j] = F[i - 1][j];
			for(int k = 1; k < 10; k++) {
				if(j > k) {
					F[i][j] += F[i - 1][j - k];
					F[i][j] %= mod;
				}
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
		cout << F[n][k] << endl;
	}
	return 0;
}

