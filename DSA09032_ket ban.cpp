#include <iostream>

using namespace std;

int parent[100001];
int siz[100001];
int kq;

int find(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void makeSet(int n) {
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
		siz[i] = 1;
	}
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
	kq = max(kq, max(siz[x], siz[y]));
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		makeSet(n);
		kq = -1e9;
		while(m--) {
			int x, y;
			cin >> x >> y;
			if(find(x) != find(y)) {
				Union(x, y);
			}
		}
		cout << kq << endl;
	}
	return 0;
}

