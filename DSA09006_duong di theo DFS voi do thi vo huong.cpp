#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int truoc[1001];

void DFS(int u, int v) {
	chuaxet[u] = false;
	if(u == v) return;
	for(int i : ke[u]) {
		if(chuaxet[i]) {
			truoc[i] = u;
			DFS(i, v);
		}
	}
}

void findPath(int u, int v) {
	memset(chuaxet, true, sizeof(chuaxet));
	memset(truoc, -1, sizeof(truoc));
	DFS(u, v);
	stack<int> st;
	while(v != -1) {
		st.push(v);
		v = truoc[v];
	}
	if(st.top() != u) cout << -1;
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
		int n, e, u, v;
		cin >> n >> e >> u >> v;
		for(int i = 1; i <= n; i++) ke[i].clear();
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		findPath(u, v);
		cout << endl;
	}
	return 0;
}

