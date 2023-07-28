#include <iostream>
#include <cstring>

using namespace std;

int qhd(string x, string y, string z, int a, int b, int c) {
	int f[a + 1][b + 1][c + 1];
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			for(int k = 1; k <= c; k++) {
				if(x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) {
					f[i][j][k] = f[i - 1][j - 1][k - 1] + 1;
				}
				else {
					f[i][j][k] = max(f[i - 1][j][k], max(f[i][j - 1][k], f[i][j][k - 1]));
				}
			}
		}
	}
	return f[a][b][c];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		string x, y, z;
		cin >> x >> y >> z;
		cout << qhd(x, y, z, a, b, c) << endl;
	}
	return 0;
}

