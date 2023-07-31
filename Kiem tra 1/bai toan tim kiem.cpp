#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;
	pair<int, int> p[n];
	for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	sort(p, p + n, cmp);
	bool slot[n] = {false};
	long long kq = 0;
	for(int i = 0; i < n; i++) {
		for(int j = min(n, p[i].first) - 1; j >= 0; j--) {
			if(slot[j] == false) {
				kq += p[i].second;
				slot[j] = true;
				break;
			}
		}
	}
	cout << kq;
	return 0;
}

