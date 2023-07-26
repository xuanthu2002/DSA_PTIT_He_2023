#include <iostream>
#include <stack>

using namespace std;

int type(char c) {
	if(c == '[' || c == ']') return 2;
	if(c == '{' || c == '}') return 3;
	return 1;
}

string solve(string s) {
	stack<char> st;
	for(char c : s) {
		if(c == '(' || c == '[' || c == '{') {
			st.push(c);
		}
		else if(c == ')' || c == ']' || c == '}') {
			if(st.empty()) {
				return "NO";
			}
			else if(type(st.top()) != type(c)) {
				return "NO";
			}
			else {
				st.pop();
			}
		}
	}
	if(!st.empty()) return "NO";
	return "YES";
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

