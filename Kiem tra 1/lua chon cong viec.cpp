#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	pair<int, int> p[n];
	for(int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, cmp);
	long long kq = 0, cur = 0;
	for(int i = 0; i < n; i++) {
		if(p[i].first > cur) {
			kq += p[i].second;
			cur = p[i].first;
		}
	}
	cout << kq;
	return 0;
}
// TLE :)))
