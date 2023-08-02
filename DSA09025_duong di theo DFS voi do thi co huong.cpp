#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[1001];
bool visited[1001];
int truoc[1001];

void DFS(int u, int v) {
	visited[u] = true;
	truoc[u] = v;
	for(int j : adj[u]) {
		if(!visited[j]) {
			DFS(j, u);
		}
	}
}

void path(int s, int v) {
	stack<int> st;
	while(v != -1) {
		st.push(v);
		v = truoc[v];
	}
	if(st.top() != s) cout << -1;
	else {
		while(!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int v, e, x, y;
		cin >> v >> e >> x >> y;
		for(int i = 1; i <= v; i++) {
			adj[i].clear();
			visited[i] = false;
			truoc[i] = -1;
		}
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		DFS(x, -1);
		path(x, y);
		cout << endl;
	}
	return 0;
}

