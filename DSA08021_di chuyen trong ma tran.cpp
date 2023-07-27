#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int a[1001][1001], buoc[1001][1001], n, m;

int solve() {
	queue<pair<int, int>> q;
	memset(buoc, -1, sizeof(buoc));
	buoc[1][1] = 0;
	q.push({1, 1});
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		if(x == n && y == m) {
			break;
		}
		if(x > n || y > m) {
			continue;
		}
		if(x + a[x][y] <= n && buoc[x + a[x][y]][y] == -1) {
			q.push({x + a[x][y], y});
			buoc[x + a[x][y]][y] = buoc[x][y] + 1;
		}
		if(y + a[x][y] <= m && buoc[x][y + a[x][y]] == -1) {
			q.push({x, y + a[x][y]});
			buoc[x][y + a[x][y]] = buoc[x][y] + 1;
		}
	}
	return buoc[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cout << solve() << endl;
	}
	return 0;
}

