#include <iostream>
#include <cstring>

using namespace std;

int C[1005][1005];

int qhd(string a, string b) {
	memset(C, 0, sizeof(C));
	int n = a.length(), m = b.length();
	for(int i = 0; i <= n; i++) {
		C[i][0] = i;
	}
	for(int i = 0; i <= m; i++) {
		C[0][i] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i - 1] == b[j - 1]) {
				C[i][j] = C[i - 1][j - 1];
			}
			else C[i][j] = min(C[i - 1][j - 1], min(C[i - 1][j], C[i][j - 1])) + 1;
		}
	}
	return C[n][m];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		cout << qhd(a, b) << endl;
	}
	return 0;
}
