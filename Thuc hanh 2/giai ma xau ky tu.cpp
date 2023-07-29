#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isDigits(char c) {
	return c >= '0' && c <= '9';
}

string solve(string s) {
	stack<int> hs;
	stack<string> st;
	st.push("");
	hs.push(1);
	int n = s.length();
	for(int i = 0; i < n; i++) {
		if(s[i] == '[' && i > 0 && !isDigits(s[i - 1])) {
			hs.push(1);
		}
		if(isDigits(s[i])) {
			int num = 0;
			while(i < n && isDigits(s[i])) {
				num = num * 10 + s[i] - '0';
				i += 1;
			}
			i -= 1;
			hs.push(num);
		}
		else if(s[i] == ']') {
			int num = hs.top();
			hs.pop();
			string tmp = "";
			while(!st.empty() && st.top() != "[") {
				tmp = st.top() + tmp;
				st.pop();
			}
			string x = "";
			while(num--) {
				x += tmp;
			}
			if(!st.empty()) {
				st.pop();
			}
			st.push(x);
		}
		else st.push(string(1, s[i]));
	}
	string kq = "";
	while(!st.empty()) {
		kq = st.top() + kq;
		st.pop();
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}

