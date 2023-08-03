#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int n;

void BFS(int u) {
	queue<int> q;
	q.push(u);
	chuaxet[u] = false;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for(int v : ke[u]) {
			if(chuaxet[v]) {
				chuaxet[v] = false;
				q.push(v);
			}
		}
	}
}

int lienThong() {
	int kq = 0;
	for(int u = 1; u <= n; u++) {
		if(chuaxet[u]) {
			kq += 1;
			BFS(u);
		}
	}
	return kq;
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
		cout << lienThong() << endl;
	}
	return 0;
}

