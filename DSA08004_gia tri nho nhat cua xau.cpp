#include <iostream>
#include <map>
#include <queue>

using namespace std;

void solve(string s, int k) {
	map<char, int> m;
	for(char c : s) m[c] += 1;
	priority_queue<int, vector<int>> q;
	for(auto i : m) q.push(i.second);
	while(k-- && !q.empty()) {
		int x = q.top();
		q.pop();
		if(x > 1) {
			q.push(x - 1);
		}
	}
	long long kq = 0;
	while(!q.empty()) {
		int x = q.top();
		q.pop();
		kq += (long long) x * x;
	}
	cout << kq << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		solve(s, k);
	}
	return 0;
}

