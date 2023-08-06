#include <iostream>

using namespace std;

int G[101][101];
int n;

void Floyd() {
	for(int k = 1; k <= n; k++) {
		for(int u = 1; u <= n; u++) {
			for(int v = 1; v <= n; v++) {
				if(G[u][k] + G[k][v] < G[u][v]) {
					G[u][v] = G[u][k] + G[k][v];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> n >> m;
	int x, y, w;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			G[i][j] = 1e9;
		}
		G[i][i] = 0;
	}
	
	while(m--) {
		cin >> x >> y >> w;
		G[x][y] = w;
		G[y][x] = w;
	}
	Floyd();
	int q;
	cin >> q;
	while(q--) {
		cin >> x >> y;
		cout << G[x][y] << endl;
	}
	return 0;
}
