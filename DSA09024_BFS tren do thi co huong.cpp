#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		cout << u << " ";
		for(int v : adj[u]) {
			if(!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
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
		BFS(u);
		cout << endl;
	}
	return 0;
}

