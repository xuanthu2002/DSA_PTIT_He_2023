#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int d[100001];

//0.23s
int solve(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, n});
	while(!q.empty()) {
		pair<int, int> p = q.top();
		q.pop();
		if(p.second == 1) {
			return p.first;
			continue;
		}
		n = p.second;
		int cnt = p.first;
		if(n % 2 == 0) {
			q.push({cnt + 1, n / 2});
		}
		if(n % 3 == 0) {
			q.push({cnt + 1, n / 3});
		}
		q.push({cnt + 1, n - 1});
	}
}

void qhd() {
	d[1] = 0;
	for(int i = 2; i <= 100000; i++) {
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0) {
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if(i % 3 == 0) {
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}
}

int main() {
	qhd();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
//		cout << solve(n) << endl;
		cout << d[n] << endl;
	}
	return 0;
}

