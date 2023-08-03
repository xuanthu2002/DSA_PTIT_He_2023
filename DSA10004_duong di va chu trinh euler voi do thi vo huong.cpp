#include <iostream>
#include <cstring>

using namespace std;

int deg[1001];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		memset(deg, 0, sizeof(deg));
		int x, y;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			deg[x]++;
			deg[y]++;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(deg[i] % 2 != 0) {
				cnt ++;
			}
		}
		if(cnt == 0) {
			cout << 2 << endl;
		}
		else if(cnt == 2) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
