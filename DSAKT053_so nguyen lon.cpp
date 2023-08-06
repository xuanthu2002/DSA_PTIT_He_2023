#include <iostream>
#include <cstring>

using namespace std;

int qhd(string n, string m) {
	int a[n.length() + 1][m.length() + 1];
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n.length(); i++) {
		for(int j = 1; j <= m.length(); j++) {
			if(n[i - 1] == m[j - 1]) {
				a[i][j] = a[i - 1][j - 1] + 1;
			}
			else {
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			}
		}
	}
	return a[n.length()][m.length()];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string n, m;
		cin >> n >> m;
		cout << qhd(n, m) << endl;
	}
	return 0;
}

