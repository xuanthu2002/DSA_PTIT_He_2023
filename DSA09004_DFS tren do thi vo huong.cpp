#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V, E;
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
		int u;
		cin >> V >> E >> u;
		for(int i = 1; i <= V; i++) adj[i].clear();
		int x, y;
		for(int i = 0; i < E; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(visited, false, sizeof(visited));
		DFS(u);
		cout << endl;
	}
	return 0;
}

