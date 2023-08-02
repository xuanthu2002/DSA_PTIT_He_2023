#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int v, e;
		cin >> v >> e;
		vector<int> adj[v + 1];
		int x, y;
		while(e--) {
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for(int i = 1; i <= v; i++) {
			cout << i << ": ";
			for(int j : adj[i]) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

