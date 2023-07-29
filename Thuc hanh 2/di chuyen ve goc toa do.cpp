#include <iostream>

using namespace std;

int main() {
	long long F[26][26];
	for(int i = 1; i < 26; i++) {
		F[0][i] = F[i][0] = 1;
	}
	F[0][0] = 0;
	for(int i = 1; i < 26; i++) {
		for(int j = 1; j < 26; j++) {
			F[i][j] = F[i - 1][j] + F[i][j - 1];
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		cout << F[n][m] << endl;
	}
	return 0;
}

