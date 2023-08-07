#include <iostream>
#include <vector>

using namespace std;

vector<int> ke[1001];
int chuaxet[1001];

void DFS(int u) {
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			DFS(v);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			chuaxet[i] = true;
		}
		int e = n - 1;
		while(e--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		string kq = "YES";
		DFS(1);
		for(int u = 2; u <= n; u++) {
			if(chuaxet[u]) {
				kq = "NO";
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}
