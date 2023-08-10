#include <iostream>
#include <utility>
#include <map>

using namespace std;

pair<int, int> parent[101][101];
int siz[101][101];

pair<int, int> find(pair<int, int> p) {
	if(p == parent[p.first][p.second]) return p;
	return parent[p.first][p.second] = find(parent[p.first][p.second]);
}

void Union(pair<int, int> u, pair<int, int> v) {
	pair<int, int> x = find(u);
	pair<int, int> y = find(v);
	if(siz[x.first][x.second] < siz[y.first][y.second]) {
		parent[y.first][y.second] = x;
		siz[x.first][x.second] += siz[y.first][y.second];
	}
	else {
		parent[x.first][x.second] = y;
		siz[y.first][y.second] += siz[x.first][x.second];
	}
}

int main() {
	map<pair<pair<int, int>, pair<int, int>>, bool> mp;
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			parent[i][j] = {i, j};
			siz[i][j] = 1;
		}
	}
	pair<int, int> p[k];
	int u, v, x, y;
	while(m--) {
		cin >> u >> v >> x >> y;
		mp[{{u, v}, {x, y}}] = true;
		mp[{{x, y}, {u, v}}] = true;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i + 1 <= n && !mp[{{i, j}, {i + 1, j}}]) {
				if(find({i, j}) != find({i + 1, j})) {
					Union({i, j}, {i + 1, j});
				}
			}
			if(i - 1 >= 1 && !mp[{{i, j}, {i - 1, j}}]) {
				if(find({i, j}) != find({i - 1, j})) {
					Union({i, j}, {i - 1, j});
				}
			}
			if(j + 1 <= n && !mp[{{i, j}, {i, j + 1}}]) {
				if(find({i, j}) != find({i, j + 1})) {
					Union({i, j}, {i, j + 1});
				}
			}
			if(j - 1 >= 1 && !mp[{{i, j}, {i, j - 1}}]) {
				if(find({i, j}) != find({i, j - 1})) {
					Union({i, j}, {i, j - 1});
				}
			}
		}
	}
	for(int i = 0; i < k; i++) {
		cin >> p[i].first >> p[i].second;
	}
	int kq = 0;
	for(int i = 0; i < k; i++) {
		for(int j = i + 1; j < k; j++) {
			if(find(p[i]) != find(p[j])) {
				kq += 1;
			}
		}
	}
	cout << kq;
	return 0;
}

