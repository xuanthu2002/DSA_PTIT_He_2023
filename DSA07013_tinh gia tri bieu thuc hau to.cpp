#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int solve(string s) {
	stack<int> st;
	for(char c : s) {
		if(isOperator(c)) {
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if(c == '+') {
				st.push(a + b);
			}
			else if(c == '-') {
				st.push(a - b);
			}
			else if(c == '*') {
				st.push(a * b);
			}
			else if(c == '/') {
				st.push(a / b);
			}
			else {
				st.push(pow(a, b));
			}
		}
		else if(c >= '0' && c <= '9') {
			st.push((int) c - '0');
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

