#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<int> ke[1001];
bool chuaxet[1001];
int n;
map<int, int> mp;

void DFS(int u) {
	chuaxet[u] = false;
	mp[u] += 1;
	for(int v : ke[u]) {
		if(chuaxet[v]) {
			DFS(v);
		}
	}
}

int main() {
	int k, n, m;
	cin >> k >> n >> m;
	int a[k];
	for(int i = 0; i < k; i++) cin >> a[i];
	while(m--) {
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
	for(int i = 0; i < k; i++) {
		memset(chuaxet, true, sizeof(chuaxet));
		DFS(a[i]);
	}
	int kq = 0;
	for(auto i : mp) {
		if(i.second == k) {
			kq += 1;
		}
	}
	cout << kq;
	return 0;
}

