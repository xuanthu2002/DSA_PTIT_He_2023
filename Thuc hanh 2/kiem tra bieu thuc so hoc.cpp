#include <iostream>
#include <stack>

using namespace std;

string solve(string s) {
	stack<int> st;
	s += " ";
	for(int i = 0; i < s.length() - 1; i++) {
		if(s[i] == '(') {
			st.push(i);
		}
		else if(s[i] == ')') {
			if(st.empty()) return "Yes";
			else {
				int idx = st.top();
				st.pop();
				if(i - idx <= 2) return "Yes";
				if(s[i + 1] == ')' && !st.empty()) {
					int j = st.top();
					if(idx - j == 1) return "Yes";
				}
			}
		}
	}
	if(!st.empty()) return "Yes";
	return "No";
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		cout << solve(s) << endl;
	}
	return 0;
}
