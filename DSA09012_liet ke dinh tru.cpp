#include <iostream>
#include <vector>
#include <cstring>

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

void dinhTru() {
	for(int u = 1; u <= n; u++) {
		memset(chuaxet, true, sizeof(chuaxet));
		chuaxet[u] = false;
		int lienThong = 0;
		for(int i = 1; i <= n; i++) {
			if(chuaxet[i] && i != u) {
				lienThong += 1;
				DFS(i);
			}
		}
		if(lienThong > 1) {
			cout << u << " ";
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) ke[i].clear();
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		dinhTru();
		cout << endl;
	}
	return 0;
}

