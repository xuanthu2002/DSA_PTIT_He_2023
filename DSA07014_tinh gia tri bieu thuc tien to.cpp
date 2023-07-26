#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int solve(string s) {
	stack<int> st;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(isOperator(s[i])) {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			if(s[i] == '+') {
				st.push(a + b);
			}
			else if(s[i] == '-') {
				st.push(a - b);
			}
			else if(s[i] == '*') {
				st.push(a * b);
			}
			else if(s[i] == '/') {
				st.push(a / b);
			}
			else {
				st.push(pow(a, b));
			}
		}
		else if(s[i] >= '0' && s[i] <= '9') {
			st.push((int) s[i] - '0');
		}
	}
	return st.top();
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
