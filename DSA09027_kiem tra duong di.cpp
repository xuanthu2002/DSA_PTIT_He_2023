#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int truoc[1001];
int n;

void BFS(int u) {
	memset(truoc, -1, sizeof(truoc));
	memset(chuaxet, true, sizeof(chuaxet));
	queue<int> q;
	q.push(u);
	chuaxet[u] = false;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for(int v : ke[u]) {
			if(chuaxet[v]) {
				chuaxet[v] = false;
				truoc[v] = u;
				q.push(v);
			}
		}
	}
}

bool findPath(int u, int v) {
	while(v != -1) {
		if(v == u) {
			return true;
		}
		v = truoc[v];
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			chuaxet[i] = true;
		}
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		int q;
		cin >> q;
		while(q--) {
			int x, y;
			cin >> x >> y;
			BFS(x);
			cout << (findPath(x, y) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}

