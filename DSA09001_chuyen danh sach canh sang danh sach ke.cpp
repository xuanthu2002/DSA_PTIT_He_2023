#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int v, e;
		cin >> v >> e;
		int x, y;
		vector<int> adj[v + 1];
		for(int i = 0; i < e; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i = 1; i <= v; i++) {
			cout << i << ": ";
			for(auto x : adj[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

