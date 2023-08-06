#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

string solve(string s) {
	stack<string> st;
	for(char c : s) {
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			string b = st.top();
			st.pop();
			string a = st.top();
			st.pop();
			st.push(c + a + b);
		}
		else st.push(string(1, c));
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

