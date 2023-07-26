#include <iostream>
#include <stack>

using namespace std;

string solve(string s) {
	stack<string> st;
	st.push("-1");
	for(char c : s) {
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			string b = st.top();
			st.pop();
			string a = st.top();
			st.pop();
			string cal = "(" + a + c + b + ")";
			st.push(cal);
		}
		else {
			st.push(string(1, c));
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

