#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

bool A[101][101];
int F[101][101];
int n;

int solve(int a, int b, int c, int d) {
	queue<pair<int, int>> q;
	q.push({a, b});
	if(a == c && b == d) return 0;
	F[a][b] = 0;
	while(F[c][d] == -1) {
		a = q.front().first;
		b = q.front().second;
		A[a][b] = 0;
		q.pop();
		if(a == c && b == d) break;
		int x = a - 1;
		while(x >= 1 && A[x][b]) {
			F[x][b] = F[a][b] + 1;
			q.push({x, b});
			A[x][b] = 0;
			x -= 1;
		}
		x = a + 1;
		while(x <= n && A[x][b]) {
			F[x][b] = F[a][b] + 1;
			q.push({x, b});
			A[x][b] = 0;
			x += 1;
		}
		int y = b - 1;
		while(y >= 1 && A[a][y]) {
			F[a][y] = F[a][b] + 1;
			q.push({a, y});
			A[a][y] = 0;
			y -= 1;
		}
		y = b + 1;
		while(y <= n && A[a][y]) {
			F[a][y] = F[a][b] + 1;
			q.push({a, y});
			A[a][y] = 0;
			y += 1;
		}
	}
	return F[c][d];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int a, b, c, d;
	char x;
	while(t--) {
		cin >> n;
		memset(A, 0, sizeof(A));
		memset(F, -1, sizeof(F));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> x;
				if(x == 'X') A[i][j] = 0;
				else A[i][j] = 1;
			}
		}
		cin >> a >> b >> c >> d;
		cout << solve(a + 1, b + 1, c + 1, d + 1) << endl;
	}
	return 0;
}

