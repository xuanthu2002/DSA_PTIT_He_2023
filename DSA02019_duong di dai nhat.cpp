#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> ke[21];
bool chuaxet[21][21];
int n;
int kq;

void quayLui(int u, int cnt) {
	kq = max(kq, cnt);
	for(int v : ke[u]) {
		if(chuaxet[u][v]) {
			chuaxet[u][v] = chuaxet[v][u] = false;
			quayLui(v, cnt + 1);
			chuaxet[u][v] = chuaxet[v][u] = true;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int e;
		cin >> e;
		for(int i = 0; i < n; i++) {
			ke[i].clear();
		}
		int x, y;
		while(e--) {
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		kq = 0;
		for(int i = 0; i < n; i++) {
			memset(chuaxet, true, sizeof(chuaxet));
			quayLui(i, 0);
		}
		cout << kq << endl;
	}
	return 0;
}

