#include <iostream>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

const string st = "1238004765";
string en;

string xoay(string s, int a[]) {
	string res = "";
	for(int i = 0; i < 10; i++) {
		res += s[a[i]];
	}
	return res;
}

int solve() {
	queue<pair<string, int>> q;
	q.push({en, 0});
	map<string, int> m;
	string top, left, right;
	int kq = 1e9;
	while(!q.empty()) {
		top = q.front().first;
		int d = q.front().second;
		q.pop();
		left = xoay(top, l1);
		right = xoay(top, r1);
		if(!m[left]) {
			q.push({left, d + 1});
			m[left] = d + 1;
		}
		if(!m[right]) {
			q.push({right, d + 1});
			m[right] = d + 1;
		}
		if(d + 1 == 14) break;
	}
	
	queue<pair<string, int>> p;
	p.push({st, 0});
	while(!p.empty()) {
		top = p.front().first;
		int d = p.front().second;
		p.pop();
		if(m[top]) {
			kq = min(kq, m[top] + d);
		}
		left = xoay(top, l2);
		p.push({left, d + 1});
		right = xoay(top, r2);
		p.push({right, d + 1});
		if(d + 1 == 14) break;
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		en = "";
		for(int i = 0; i < 10; i++) {
			cin >> s;
			en += s;
		}
		cout << solve() << endl;
	}
	return 0;
}

