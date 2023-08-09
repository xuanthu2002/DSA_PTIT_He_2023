#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> ke[11];
bool chuaxet[11];
int n;

bool quayLui(int u, int cnt) {
	chuaxet[u] = false;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			cnt += 1;
			if(cnt == n) {
				return true;
			}
			else if(quayLui(v, cnt)) return true;
			cnt -= 1;
		}
	}
	chuaxet[u] = true;
	return false;
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
			ke[y].push_back(x);
		}
		bool kq = false;
		for(int i = 1; i <= n; i++) {
			memset(chuaxet, true, sizeof(chuaxet));
			if(quayLui(i, 1)) {
				kq = true;
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

