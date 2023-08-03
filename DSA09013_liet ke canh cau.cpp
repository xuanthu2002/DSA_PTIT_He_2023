#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

vector<int> ke[1001];
vector<pair<int, int>> canh;
bool chuaxet[1001];
int n;

void DFS(int u, int x, int y) {
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(u == x && v == y || u == y && v == x) continue;
		if(chuaxet[v]) {
			DFS(v, x, y);
		}
	}
}

void solve() {
	for(auto i : canh) {
		memset(chuaxet, true, sizeof(chuaxet));
		int lienThong = 0;
		for(int u = 1; u <= n; u++) {
			if(chuaxet[u]) {
				lienThong += 1;
				DFS(u, i.first, i.second);
			}
		}
		if(lienThong > 1) {
			cout << i.first << " " << i.second << " ";
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
		}
		canh.clear();
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			canh.push_back({x, y});
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		solve();
		cout << endl;
	}
	return 0;
}

