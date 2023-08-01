#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

int solve(int n) {
	unordered_map<int, bool> m;
	queue<pair<int, int>> q;
	q.push({n, 0});
	while(!q.empty()) {
		n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(n == 1) return cnt;
		q.push({n - 1, cnt + 1});
		for(int i = 2; i * i <= n; i++) {
			if(n % i == 0) {
				if(!m[n / i]) {
					m[n / i] = true;
					q.push({n / i, cnt + 1});
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

