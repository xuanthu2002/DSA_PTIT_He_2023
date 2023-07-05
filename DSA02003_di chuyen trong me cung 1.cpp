#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int a[11][11];
int n;

void solve() {
	if(a[0][0] == 0) {
		cout << "-1" << endl;
		return;
	}
	queue<pair<string, pair<int , int>>> q;
	q.push({"", {0, 0}});
	bool flag = false;
	while(!q.empty()) {
		pair<string, pair<int, int>> top = q.front();
		q.pop();
		int x = top.second.first;
		int y = top.second.second;
		if(x == n - 1 && y == n - 1) {
			cout << top.first << " ";
			flag = true;
			continue;
		}
		if(a[x + 1][y] > 0) {
			q.push({top.first + "D", {x + 1, y}});
		}
		if(a[x][y + 1] > 0) {
			q.push({top.first + "R", {x, y + 1}});
		}
	}
	if(!flag) {
		cout << "-1";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		solve();	
	}
	return 0;
}

