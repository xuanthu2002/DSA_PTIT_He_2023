#include <iostream>

using namespace std;

long long F[26][26];

void qhd() {
	for(int i = 0; i < 26; i++) {
		F[i][0] = F[0][i] = 1;
	}
	F[0][0] = 0;
	for(int i = 1; i < 26; i++) {
		for(int j = 1; j < 26; j++) {
			F[i][j] = F[i - 1][j] + F[i][j - 1];
		}
	}
}

int main() {
	qhd();
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		cout << F[n][m] << endl;
	}
	return 0;
}

