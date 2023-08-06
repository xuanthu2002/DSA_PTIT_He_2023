#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> ke[1001];
bool chuaxet[1001];
int F[1001];
int n;

void dijkstra(int u) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, u});
	F[u] = 0;
	while(!q.empty()) {
		u = q.top().second;
		int d = q.top().first;
		chuaxet[u] = false;
		q.pop();
		for(auto i : ke[u]) {
			if(chuaxet[i.first]) {
				if(d + i.second < F[i.first]) {
					q.push({d + i.second, i.first});
					F[i.first] = d + i.second;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e, u;
		cin >> n >> e >> u;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			chuaxet[i] = true;
			F[i] = 1e9;
		}
		while(e--) {
			int x, y, z;
			cin >> x >> y >> z;
			ke[x].push_back({y, z});
			ke[y].push_back({x, z});
		}
		dijkstra(u);
		for(int i = 1; i <= n; i++) {
			cout << F[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

