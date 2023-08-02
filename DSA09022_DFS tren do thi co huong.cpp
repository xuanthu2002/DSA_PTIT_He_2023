#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
	visited[u] = true;
	cout << u << " ";
	for(int v : adj[u]) {
		if(!visited[v]) {
			DFS(v);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int v, e, u;
		cin >> v >> e >> u;
		for(int i = 1; i <= v; i++) {
			adj[i].clear();
			visited[i] = false;
		}
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		DFS(u);
		cout << endl;
	}
	return 0;
}

