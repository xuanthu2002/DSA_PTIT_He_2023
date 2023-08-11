#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int a[501][501];
int F[501][501];
int r, c;

int solve() {
	queue<pair<int, int>> q;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(a[i][j] == 2) {
				q.push({i, j});
				F[i][j] = 0;
			}
		}
	}
	int x, y, nx, ny;
	int kq = -1;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && a[nx][ny] == 1) {
				q.push({nx, ny});
				F[nx][ny] = F[x][y] + 1;
				a[nx][ny] = 2;
				kq = max(kq, F[nx][ny]);
			}
		}
	}
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(a[i][j] == 1) {
				kq = -1;
				break;
			}
		}
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> r >> c;
		for(int i = 1; i <= r; i++) {
			for(int j = 1; j <= c; j++) {
				cin >> a[i][j];
			}
		}
		cout << solve() << endl;
	}
	return 0;
}
