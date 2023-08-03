#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int truoc[1001];

void BFS(int u, int v) {
	memset(truoc, -1, sizeof(truoc));
	memset(chuaxet, true, sizeof(chuaxet));
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
				if(i == v) {
					return;
				}
			}
		}
	}
}

void path(int u, int v) {
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
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		path(u, v);
		cout << endl;
	}
	return 0;
}

