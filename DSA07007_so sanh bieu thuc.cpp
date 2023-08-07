#include <iostream>
#include <stack>

using namespace std;

string xuLy(string s) {
	stack<char> st;
	for(int i = 1; i < s.length(); i++) {
		if(s[i] == '(') {
			if(s[i - 1] == '(') {
				if(!st.empty()) st.push(st.top());
			}
			else st.push(s[i - 1]);
		}
		else if(s[i] == ')' && !st.empty()) {
			st.pop();
		}
		else if(!st.empty() && st.top() == '-') {
			if(s[i] == '+') s[i] = '-';
			else if(s[i] == '-') s[i] = '+';
		}
	}
	string kq = "";
	for(char c : s) {
		if(c == '(' || c == ')') continue;
		kq = kq + c;
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string p1, p2;
		cin >> p1 >> p2;
		if(xuLy(p1) == xuLy(p2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

