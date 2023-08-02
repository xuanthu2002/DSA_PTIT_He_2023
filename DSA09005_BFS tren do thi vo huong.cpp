#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int V, E;
vector<int> adj[1001];
bool visited[1001];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int v = q.front();
		visited[v] = true;
		cout << v << " ";
		q.pop();
		for(int i : adj[v]) {
			if(!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
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
		BFS(u);
		cout << endl;
	}
	return 0;
}

