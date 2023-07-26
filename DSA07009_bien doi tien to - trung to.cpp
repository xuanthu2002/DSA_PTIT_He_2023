#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string solve(string s) {
	stack<string> st;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(isOperator(s[i])) {
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			st.push("(" + a + s[i] + b + ")");
		}
		else {
			st.push(string(1, s[i]));
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

