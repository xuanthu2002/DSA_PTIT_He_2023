#include <iostream>
#include <cstring>

using namespace std;

int a[502][502];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m;

void DFS(int x, int y) {
	a[x][y] = 0;
	for(int i = 0; i < 8; i++) {
		if(a[x + dx[i]][y + dy[i]] == 1) {
			DFS(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][j] = (c == 'W' ? 1 : 0);
		}
	}
	int kq = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == 1) {
				kq += 1;
				DFS(i, j);
			}
		}
	}
	cout << kq;
	return 0;
}

