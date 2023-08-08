#include <iostream>
#include <set>
#include <stack>

using namespace std;

set<int> ke[1001];
int truoc[1001];
int en;

bool DFS(int u, int v) {
	truoc[u] = v;
	for(int i : ke[u]) {
		if(truoc[i] == -1) {
			if(DFS(i, u)) return true;
		}
		else if(i != v && i == 1) {
			en = u;
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			ke[i].clear();
			truoc[i] = -1;
		}
		while(m--) {
			int x, y;
			cin >> x >> y;
			ke[x].insert(y);
			ke[y].insert(x);
		}
		en = 0;
		if(DFS(1, 0)) {
			stack<int> st;
			st.push(1);
			while(en != 0) {
				st.push(en);
				en = truoc[en];
			}
			while(!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
		}
		else cout << "NO";
		cout << endl;
	}
	return 0;
}

