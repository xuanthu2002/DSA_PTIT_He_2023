#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int d[8][8];
const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int x, y, u, v;

bool ok(int a, int b) {
	return a >= 0 && a < 8 && b >= 0 && b < 8 && d[a][b] == -1;
}

int solve() {
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	q.push({x, y});
	d[x][y] = 0;
	while(d[u][v] == -1) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++) {
			if(ok(x + dx[i], y + dy[i])) {
				d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
				q.push({x + dx[i], y + dy[i]});
			}
		}
	}
	return d[u][v];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string xy, uv;
		cin >> xy >> uv;
		x = xy[0] - 'a';
		y = xy[1] - '1';
		u = uv[0] - 'a';
		v = uv[1] - '1';
		cout << solve() << endl;
	}
	return 0;
}

