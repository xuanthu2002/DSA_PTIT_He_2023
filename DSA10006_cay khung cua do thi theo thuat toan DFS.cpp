#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
vector<pair<int, int>> kq;

void DFS(int u) {
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			kq.push_back({u, v});
			DFS(v);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, e, u;
		cin >> n >> e >> u;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			chuaxet[i] = true;
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		kq.clear();
		DFS(u);
		if(kq.size() != n - 1) {
			cout << -1 << endl;
		}
		else {
			for(auto i : kq) {
				cout << i.first << " " << i.second << endl;
			}
		}
	}
	return 0;
}

