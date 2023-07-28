#include <iostream>
#include <cstring>

using namespace std;

long long qhd(string s) {
	int n = s.length();
	long long f[n + 1][n + 1];
	memset(f, 0, sizeof(f));
	long long kq = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			f[i][j] = f[i][j - 1] * 10 + s[j - 1] - '0';
			kq += f[i][j];
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

