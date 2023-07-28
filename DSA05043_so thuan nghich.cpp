#include <iostream>
#include <cstring>

using namespace std;

int qhd(string s) {
	int n = s.length();
	bool f[n][n];
	memset(f, false, sizeof(f));
	for(int i = 0; i < n; i++) f[i][i] = true;
	int kq = 0;
	for(int len = 2; len <= n; len++) {
		for(int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			if(s[i] == s[j] && len > 2) {
				f[i][j] = f[i + 1][j - 1];
			}
			else f[i][j] = (s[i] == s[j]);
			if(f[i][j]) {
				kq = max(kq, j - i + 1);
			}
		}
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << qhd(s) << endl;
	}
	return 0;
}

