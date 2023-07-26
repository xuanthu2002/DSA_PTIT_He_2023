#include <iostream>
#include <stack>

using namespace std;

bool check_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priority(char c) {
	if(c == '^') {
		return 2;
	}
	if(c == '*' || c == '/') {
		return 1;
	}
	return 0;
}

void trungto_hauto(string s) {
	stack<char> st;
	int n = s.length();
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(check_operator(s[i])) {
			while(!st.empty() && check_operator(st.top()) && priority(s[i]) <= priority(st.top())) {
				cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			while(!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			if(!st.empty()) {
				st.pop();
			}
		}
		else cout << s[i];
	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		trungto_hauto(s);
		cout << endl;
	}
	return 0;
}
