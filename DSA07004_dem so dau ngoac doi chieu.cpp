#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		stack<char> st;
		for(char c : s) {
			if(c == '(' || c == ')' && st.empty()) st.push(c);
			else if(c == ')') {
				if(st.top() == '(') {
					st.pop();
				}
				else st.push(c);
			}
		}
		int open = 0, close = 0;
		while(!st.empty()) {
			open += st.top() == '(';
			close += st.top() == ')';
			st.pop();
		}
		int kq = open / 2 + close / 2;
		if(open & 1) {
			kq += 2;
		}
		cout << kq << endl;
	}
	return 0;
}

