#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int p[n], q[m];
		for(int i = 0; i < n; i++) cin >> p[i];
		for(int i = 0; i < m; i++) cin >> q[i];
		map<int, int> kq;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				kq[i + j] += p[i] * q[j];
			}
		}
		for(auto i : kq) {
			cout << i.second << " ";
		}
		cout << endl;
	}
	return 0;
}

