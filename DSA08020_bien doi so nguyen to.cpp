#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <utility>

using namespace std;

map<string, bool> prime;

void sang() {
	bool nt[10000];
	memset(nt, true, sizeof(nt));
	for(int i = 2; i * i <= 9999; i++) {
		if(nt[i]) {
			for(int j = i * i; j <= 9999; j += i) {
				nt[j] = false;
			}
		}
	}
	for(int i = 1000; i <= 9999; i++) {
		if(nt[i]) {
			prime[to_string(i)] = true;
		}
	}
}

int solve(string a, string b) {
	queue<pair<string, int>> q;
	map<string, bool> m;
	q.push({a, 0});
	while(!q.empty()) {
		string s = q.front().first;
		int d = q.front().second;
		q.pop();
		if(s == b) {
			return d;
		}
		for(int i = 0; i < 4; i++) {
			string tmp = s;
			for(int j = '0'; j <= '9'; j++) {
				tmp[i] = j;
				if(prime[tmp] && !m[tmp] && stoi(tmp) >= 1000) {
					q.push({tmp, d + 1});
					m[tmp] = true;
				}
			}
		}
	}
	return 0;
}

int main() {
	sang();
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
