#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> ke[1001];
int color[1001];
int n;

bool DFS(int u, int c) {
	color[u] = c;
	for(int v : ke[u]) {
		if(color[v] == -1) {
			if(!DFS(v, abs(c - 1))) return false;
		}
		else if(color[v] == c) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			color[i] = -1;
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		string kq = "YES";
		for(int u = 1; u <= n; u++) {
			if(color[u] == -1) {
				if(!DFS(u, 0)) {
					kq = "NO";
					break;
				}
			}
		}
		cout << kq << endl;
	}
	return 0;
}
