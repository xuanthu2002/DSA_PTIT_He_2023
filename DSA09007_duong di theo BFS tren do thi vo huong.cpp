#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int truoc[1001];

void BFS(int u, int v) {
	queue<int> q;
	q.push(u);
	chuaxet[u] = false;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for(int i : ke[u]) {
			if(chuaxet[i]) {
				chuaxet[i] = false;
				truoc[i] = u;
				q.push(i);
				if(i == v) return;
			}
		}
	}
}

void findPath(int u, int v) {
	memset(chuaxet, true, sizeof(chuaxet));
	memset(truoc, -1, sizeof(truoc));
	BFS(u, v);
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

