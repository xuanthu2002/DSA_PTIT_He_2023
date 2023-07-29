#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
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
		int kq = 0, cur = 0;
		for(int i = 0; i < n; i++) {
			if(p[i].first >= cur) {
				kq += 1;
				cur = p[i].second;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

