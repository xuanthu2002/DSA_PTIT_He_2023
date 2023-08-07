#include <iostream>
#include <vector>

using namespace std;

vector<int> ke[1001];
int chuaxet[1001];
int color[1001];

bool DFS(int u) {
	color[u] = 1;
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			if(DFS(v)) return true;
		}
		else if(color[v] == 1) return true;
	}
	color[u] = 2;
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			chuaxet[i] = true;
			color[i] = 0;
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		string kq = "NO";
		for(int u = 1; u <= n; u++) {
			if(chuaxet[u]) {
				if(DFS(u)) {
					kq = "YES";
					break;
				}
			}
		}
		cout << kq << endl;
	}
	return 0;
}

