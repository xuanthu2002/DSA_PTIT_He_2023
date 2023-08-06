#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, pair<int, int>> TX;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int a[501][501];
int F[501][501];
int n, m;

void BFS() {
	memset(F, -1, sizeof(F));
	F[1][1] = a[1][1];
	priority_queue<TX, vector<TX>, greater<TX>> q;
	q.push({a[1][1], {1, 1}});
	while(F[n][m] == -1) {
		TX top = q.top();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = top.second.first + dx[i];
			int ny = top.second.second + dy[i];
			if(F[nx][ny] == -1 && nx <= n && ny <= m && nx >= 1 & ny >= 1) {
				F[nx][ny] = F[top.second.first][top.second.second] + a[nx][ny];
				q.push({F[nx][ny], {nx, ny}});
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		BFS();
		cout << F[n][m] << endl;
	}
	return 0;
}
