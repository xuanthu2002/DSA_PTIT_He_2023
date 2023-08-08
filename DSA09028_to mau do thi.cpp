#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> ke[11];
int color[11];
int n, m;

bool ok(int u, int c) {
	for(int v : ke[u]) {
		if(color[v] == c) return false;
	}
	return true;
}

bool quayLui(int u) {
	for(int j = 1; j <= m; j++) {
		if(ok(u, j)) {
			color[u] = j;
			if(u == n) {
				for(int v = 1; v <= n; v++) {
					if(color[v] == 0) return false;
				}
				return true;
			}
			else if(quayLui(u + 1)) {
				return true;
			}
			color[u] = 0;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e >> m;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			color[i] = 0;
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		if(quayLui(1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

