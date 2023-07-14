#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int max_a = -1e9, min_b = 1e9;
		int x;
		for(int i = 0; i < n; i++) {
			cin >> x;
			max_a = max(max_a, x);
		}
		for(int i = 0; i < m; i++) {
			cin >> x;
			min_b = min(min_b, x);
		}
		cout << (long long) max_a * min_b << endl;
	}
	return 0;
}

