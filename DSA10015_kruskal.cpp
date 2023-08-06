#include <iostream>
#include <algorithm>

using namespace std;

int parent[101];
int siz[101];
int n, m;

struct canh {
	int dau, cuoi, ts;	
} dsc[10001];

bool operator < (canh a, canh b) {
	return a.ts < b.ts;
}
	
void makeset() {
	for(int i = 1; i <= n; i++) {
		parent[i] = -1;
		siz[i] = 1;
	}
}

int find(int x) {
	while(parent[x] != -1) {
		x = parent[x];
	}
	return x;
}

void Union(int x, int y) {
	if(siz[x] < siz[y]) {
		parent[x] = y;
		siz[y] += siz[x];
	}
	else {
		parent[y] = x;
		siz[x] += siz[y];
	}
}

int Kruskal() {
	int kq = 0;
	for(int i = 0; i < m; i++) {
		int u = find(dsc[i].dau);
		int v = find(dsc[i].cuoi);
		if(u != v) {
			Union(u, v);
			kq += dsc[i].ts;
		}
	}
	return kq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			cin >> dsc[i].dau;
			cin >> dsc[i].cuoi;
			cin >> dsc[i].ts;
		}
		makeset();
		sort(dsc, dsc + m);
		cout << Kruskal() << endl;
	}
	return 0;
}
