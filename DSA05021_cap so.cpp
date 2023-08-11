#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		pair<int, int> p[n];
		for(int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p, p + n, cmp);
		int f[n], kq = -1e9;
		for(int i = 0; i < n; i++) {
			f[i] = 1;
			for(int j = 0; j < i; j++) {
				if(p[j].second < p[i].first) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			kq = max(kq, f[i]);
		}
		cout << kq << endl;
	}
	return 0;
}

