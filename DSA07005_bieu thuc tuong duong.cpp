#include <iostream>
#include <stack>

using namespace std;

void solve(string s) {
	stack<char> st;
	for(int i = 1; i < s.length(); i++) {
		if(s[i] == '(') {
			if(s[i - 1] == '-' || s[i - 1] == '+') {
				st.push(s[i - 1]);
			}
			if(!st.empty() && s[i - 1] == '(') {
				st.push(st.top());
			}
		}
		if(s[i] == ')' && !st.empty()) {
			st.pop();
		}
		if(!st.empty() && st.top() == '-') {
			if(s[i] == '+') {
				s[i] = '-';
			}
			else if(s[i] == '-') {
				s[i] = '+';
			}
		}
	}
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(' || s[i] == ')') continue;
		cout << s[i];
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		solve(s);
		cout << endl;
	}
	return 0;
}

