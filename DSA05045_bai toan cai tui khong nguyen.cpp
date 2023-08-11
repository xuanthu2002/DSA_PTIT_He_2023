#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

bool cmp(pair<pair<int, int>, float> a, pair<pair<int, int>, float> b) {
	return a.second > b.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, w;
		cin >> n >> w;
		pair<pair<int, int>, float> p[n];
		for(int i = 0; i < n; i++) {
			cin >> p[i].first.first >> p[i].first.second;
			p[i].second = (float) p[i].first.first / p[i].first.second;
		}
		sort(p, p + n, cmp);
		int sumValue = 0, idx = 0;
		float sumWeight = 0;
		for(int i = 0; i < n; i++) {
			if(sumValue <= w) {
				sumValue += p[i].first.second;
				sumWeight += p[i].first.first;
				idx = i;
			}
		}
		if(sumValue > w) {
			sumWeight -= (float) (sumValue - w) * p[idx].second;
		}
		cout << fixed << setprecision(2) << sumWeight << endl;
	}
	return 0;
}

