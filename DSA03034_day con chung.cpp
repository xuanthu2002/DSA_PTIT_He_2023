#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m], c[k];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		for(int i = 0; i < k; i++) cin >> c[i];
		int x = 0, y = 0, z = 0;
		bool flag = false;
		while(x < n && y < m && z < k) {
			if(a[x] == b[y] && b[y] == c[z]) {
				cout << a[x] << " ";
				flag = true;
				x += 1;
				y += 1;
				z += 1;
			}
			else if(a[x] <= b[y] && a[x] <= c[z]) {
				x += 1;
			}
			else if(b[y] <= a[x] && b[y] <= c[z]) {
				y += 1;
			}
			else {
				z += 1;
			}
		}
		if(!flag) cout << "NO";
		cout << endl;
	}
	return 0;
}

