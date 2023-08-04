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

string solve() {
	memset(chuaxet, true, sizeof(chuaxet));
	DFS(1);
	for(int i = 2; i <= n; i++) {
		if(chuaxet[i]) {
			return "NO";
		}
	}
	return "YES";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int e;
		cin >> n >> e;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
		}
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		cout << solve() << endl;
	}
	return 0;
}

