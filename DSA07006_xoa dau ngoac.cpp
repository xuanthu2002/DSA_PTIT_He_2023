#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <set>

using namespace std;

string s;
vector<pair<int, int>> v;
bool F[201];
set<string> kq;

void quayLui(int i, int cnt) {
	for(int j = 0; j < 2; j++) {
		F[v[i].first] = F[v[i].second] = j;
		cnt += j;
		if(i == v.size() - 1) {
			if(cnt > 0) {
				string res = "";
				for(int idx = 0; idx < s.length(); idx++) {
					if(F[idx]) continue;
					res += s[idx];
				}
				kq.insert(res);
			}
		}
		else quayLui(i + 1, cnt);
	}
}

int main() {
	getline(cin, s);
	stack<int> st;
	for(int i = 0; i < s.length(); i++) {
		F[i] = false;
		if(s[i] == '(') st.push(i);
		else if(s[i] == ')') {
			v.push_back({st.top(), i});
			st.pop();
		}
	}
	quayLui(0, 0);
	for(string i : kq) {
		cout << i << endl;
	}
	return 0;
}
