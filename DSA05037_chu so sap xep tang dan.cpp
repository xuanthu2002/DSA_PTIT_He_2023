#include <iostream>

using namespace std;

long long F[101][10];
long long KQ[101];
int mod = 1e9 + 7;

void qhd() {
	for(int i = 0; i < 10; i++) F[1][i] = 1;
	for(int i = 2; i <= 100; i++) {
		for(int j = 0; j < 10; j++) {
			F[i][j] = 0;
			for(int k = j; k < 10; k++) {
				F[i][j] += F[i - 1][k];
				F[i][j] %= mod;
			}
		}
	}
	for(int i = 1; i <= 100; i++) {
		KQ[i] = 0;
		for(int j = 0; j < 10; j++) {
			KQ[i] += F[i][j];
			KQ[i] %= mod;
		}
	}
}

int main() {
	qhd();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << KQ[n] << endl;
	}
	return 0;
}

