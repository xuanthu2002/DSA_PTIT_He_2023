#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		int i = 0, j = 0;
		int cnt = 0;
		vector<int> v;
		while(i < n && j < m) {
			if(a[i] <= b[j]) {
				v.push_back(a[i]);
				i += 1;
			}
			else {
				v.push_back(b[j]);
				j += 1;
			}
		}
		while(i < n) {
			v.push_back(a[i]);
			i += 1;
		}
		while(j < m) {
			v.push_back(b[j]);
			j += 1;
		}
		cout << v[k - 1] << endl;
	}
	return 0;
}

