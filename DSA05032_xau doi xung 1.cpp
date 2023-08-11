#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		string rev = s;
		reverse(rev.begin(), rev.end());
		int n = s.length();
		int f[n + 1][n + 1];
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(s[i - 1] == rev[j - 1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else {
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				}
			}
		}
		cout << n - f[n][n] << endl;
	}
	return 0;
}

