#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> f;

bool contain(string s, int n) {
	for(char c : s) {
		if(c - '0' == n) return true;
	}
	return false;
}

void init() {
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while(!q.empty()) {
		string s = q.front();
		q.pop();
		if(s.length() >= 7) return;
		f.push_back(stoi(s));
		for(int i = 0; i < 6; i++) {
			if(!contain(s, i)) {
				q.push(s + to_string(i));
			}
		}
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		int i = 0;
		while(f[i] < l) {
			i += 1;
		}
		int kq = 0;
		while(f[i] <= r) {
			kq += 1;
			i += 1;
		}
		cout << kq << endl;
	}
	return 0;
}

