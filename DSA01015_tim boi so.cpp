#include <iostream>
#include <queue>

using namespace std;

vector<long long> d;

void init() {
	queue<long long> q;
	q.push(9);
	while(!q.empty()) {
		long long top = q.front();
		q.pop();
		d.push_back(top);
		if(top >= 1e14) {
			break;
		}
		q.push(top * 10);
		q.push(top * 10 + 9);
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(long long i : d) {
			if(i % n == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

