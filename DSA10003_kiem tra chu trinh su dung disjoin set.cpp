#include <iostream>

using namespace std;

int parent[1001];
int siz[1001];

void makeSet(int n) {
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		siz[i] = 1;
	}
}

int find(int u) {
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void Union(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(siz[x] < siz[y]) {
		parent[y] = x;
		siz[x] += siz[y];
	}
	else {
		parent[x] = y;
		siz[y] += siz[x];
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, e;
		cin >> n >> e;
		makeSet(n);
		string kq = "NO";
		while(e--) {
			int u, v;
			cin >> u >> v;
			if(find(u) == find(v)) {
				kq = "YES";
			}
			else Union(u, v);
		}
		cout << kq << endl;
	}
	return 0;
}

