#include <iostream>
#include <queue>

using namespace std;

long long BDN(int n) {
	queue<long long> q;
	q.push(1);
	while(!q.empty()) {
		long long x = q.front();
		q.pop();
		if(x % n == 0) {
			return x;
		}
		q.push(x * 10);
		q.push(x * 10 + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << BDN(n) << endl;
	}
	return 0;
}

