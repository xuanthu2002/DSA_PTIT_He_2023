#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

vector<long long> ugly;

void sang() {
	
	unordered_map<long long, bool> F;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	q.push(1);
	long long tmp;
	while(ugly.size() < 10000) {
		tmp = q.top();
		q.pop();
		ugly.push_back(tmp);
		F[tmp] = true;
		if(!F[tmp << 1]) {
			q.push(tmp << 1);
			F[tmp << 1] = true;
		}
		if(!F[tmp * 3]) {
			F[tmp * 3] = true;
			q.push(tmp * 3);
		}
		if(!F[tmp * 5]) {
			F[tmp * 5] = true;
			q.push(tmp * 5);
		}
	}
}

int main() {
	sang();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ugly[n - 1] << endl;
	}
	return 0;
}

