#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int priority(char c) {
	if(c == '*' || c == '/') return 1;
	if(c == '+' || c == '-') return 0;
	return -1;
}

string hauto(string s) {
	stack<char> st;
	string pos = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') st.push(s[i]);
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			while(!st.empty() && priority(st.top()) >= priority(s[i])) {
				pos = pos + st.top() + " ";
				st.pop();
			}
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			while(!st.empty() && st.top() != '(') {
				pos = pos + st.top() + " ";
				st.pop();
			}
			st.pop();
		}
		else {
			string num = "";
			while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
				num += s[i];
				i += 1;
			}
			i -= 1;
			pos += num + " ";
		}
	}
	while(!st.empty()) {
		pos = pos + st.top() + " ";
		st.pop();
	}
	return pos;
}

long long solve(string s) {
	s = hauto(s);
	stack<long long> st;
	stringstream ss(s);
	while(ss >> s) {
		if(s == "+" || s == "-" || s == "*" || s == "/") {
			long long b = st.top();
			st.pop();
			long long a = st.top();
			st.pop();
			if(s == "+") st.push(a + b);
			else if(s == "-") st.push(a - b);
			else if(s == "*") st.push(a * b);
			else if(s == "/") st.push(a / b);
		}
		else st.push(stoll(s));
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

