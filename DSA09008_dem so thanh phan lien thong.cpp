#include <iostream>
#include <vector>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int n;

void DFS(int u) {
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			DFS(v);
		}
	}
}

int lienThong() {
	int kq = 0;
	for(int u = 1; u <= n; u++) {
		if(chuaxet[u]) {
			kq += 1;
			DFS(u);
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

