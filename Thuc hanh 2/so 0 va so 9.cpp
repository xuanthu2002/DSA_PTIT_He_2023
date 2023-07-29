#include <iostream>
#include <queue>

using namespace std;

long long solve(int n) {
	queue<long long> q;
	q.push(9);
	while(!q.empty()) {
		if(q.front() % n == 0) return q.front();
		q.push(q.front() * 10);
		q.push(q.front() * 10  + 9);
		q.pop();
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

