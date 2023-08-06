#include <iostream>
#include <set>
#include <cstring>

using namespace std;

long long F[200001];
long long sum[200001];
set<int> ke[200001];
int n;

void DFS(int u) {
	for(int v : ke[u]) {
		DFS(v);
		sum[u] += sum[v] + 1;
		F[u] += F[v];
	}
	F[u] += sum[u];
}

int main() {
	cin >> n;
	for(int i = 2; i <= n ; i++) {
		int x;
		cin >> x;
		ke[x].insert(i);
	}
	for(int i = 1; i <= n; i++) {
		F[i] = 1;
		sum[i] = 0;
	}
	DFS(1);
	for(int i = 1; i <= n; i++) {
		cout << F[i] << " ";
	}
	return 0;
}

