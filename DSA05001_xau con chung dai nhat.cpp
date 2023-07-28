#include <iostream>
#include <cstring>

using namespace std;

int qhd(string s1, string s2) {
	int n = s1.length(), m = s2.length();
	int f[n + 1][m + 1];
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				f[i][j] = f[i- 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i -1][j], f[i][j - 1]);
			}
		}
	}
	return f[n][m];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << qhd(s1, s2) << endl;
	}
	return 0;
}

