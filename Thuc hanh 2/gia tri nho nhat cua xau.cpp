#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long long solve(string s, int k) {
	unordered_map<char, int> m;
	for(char c : s) m[c] += 1;
	priority_queue<int, vector<int>> q;
	for(auto i : m) {
		q.push(i.second);
	}
	while(!q.empty() && k--) {
		int x = q.top();
		q.pop();
		q.push(x - 1);
	}
	long long kq = 0;
	while(!q.empty()) {
		long long x = q.top();
		kq += x * x;
		q.pop();
	}
	return kq;
} 

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		cout << solve(s, k) << endl;
	}
	return 0;
}

