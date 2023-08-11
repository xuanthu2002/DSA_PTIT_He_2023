#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int BFS(unordered_set<string> mySet, string s, string t) {
	queue<string> q;
	q.push(s);
	int kq = 1;
	while(!q.empty()) {
		queue<string> que = q;
		kq += 1;
		while(!que.empty()) {
			s = que.front();
			que.pop();
			q.pop();
			for(int i = 0; i < s.length(); i++) {
				char c = s[i];
				for(char x = 'A'; x <= 'Z'; x++) {
					s[i] = x;
					if(s == t) return kq;
					if(mySet.find(s) != mySet.end()) {
						q.push(s);
						mySet.erase(s);
					}
				}
				s[i] = c;
			}
		}
	}
	return kq;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		string s, t, x;
		cin >> s >> t;
		unordered_set<string> se;
		for(int i = 0; i < n; i++) {
			cin >> x;
			se.insert(x);
		}
		cout << BFS(se, s, t) << endl;
	}
	return 0;
}
