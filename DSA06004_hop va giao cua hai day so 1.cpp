#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		set<int> s;
		map<int, int> mp;
		int x;
		int a[n], b[m];
		int cnt[100001] = {0};
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]] = 1;
		}
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int i = 0, j = 0;
		while(i < n && j < m) {
			if(a[i] == b[j]) {
				cout << a[i] << " ";
				i += 1;
				j += 1;
			}
			else if(a[i] < b[j]) {
				cout << a[i] << " ";
				i += 1;
			}
			else {
				cout << b[j] << " ";
				j += 1;
			}
		}
		while(i < n) cout << a[i++] << " ";
		while(j < m) cout << b[j++] << " ";
		cout << endl;
		for(int i = 0; i < m; i++) {
			if(cnt[b[i]] == 1) {
				cout << b[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

