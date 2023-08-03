#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, e;
		cin >> n >> e;
		int deg[n + 1] = {0};
		while(e--) {
			int x, y;
			cin >> x >> y;
			deg[x] -= 1;
			deg[y] += 1;
		}
		int kq = 1;
		for(int i = 1; i <= n; i++) {
			if(deg[i] != 0) {
				kq = 0;
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

