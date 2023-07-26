#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<long long> v;

void init() {
	queue<long long> q;
	q.push(9);
	while(!q.empty()) {
		long long s = q.front();
		q.pop();
		if(s >= 100000000000) break;
		v.push_back(s);
		q.push(s * 10);
		q.push(s * 10 + 9);
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(auto x : v) {
			if(x % n == 0) {
				cout << x;
				break;
			}
		}
		cout << endl;
	}
	return 0;
}

