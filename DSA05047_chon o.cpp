#include <iostream>

using namespace std;

const int d[] = {0, 1, 2, 4, 5, 8, 9, 10};

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, ans = -1e9, s = -1e9;
		cin >> n;
		int a[4][n + 1], f[n + 1][11] = {};
		for(int i = 0; i < 4; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> a[i][j];
				ans = max(ans, a[i][j]);
			}
		}
		if(ans <= 0) {
			cout << ans << endl;
			continue;
		}
		for(int j = 1; j <= n; j++) {
			for(int k = 0; k < 8; k++) {
				for(int i = 0; i < 4; i++) {
					if(d[k] & (1 << i)) {
						f[j][d[k]] += a[i][j];
					}
				}
				int x = -1e9;
				for(int i = 0; i < 8; i++) {
					if((d[k] | d[i]) == (d[k] ^ d[i])) {
						x = max(x, f[j - 1][d[i]]);
					}
				}
				f[j][d[k]] += x;
			}
		}
		for(int i = 0; i < 8; i++) {
			s = max(s, f[n][d[i]]);
		}
		cout << s << endl;
	}
	return 0;
}

