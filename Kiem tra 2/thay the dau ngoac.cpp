#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		stack<int> st;
		bool vt[s.length()] = {false};
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(') {
				st.push(i);
			}
			else if(s[i] == ')') {
				if(st.empty()) {
					vt[i] = true;
				}
				else {
					s[st.top()] = '0';
					s[i] = '1';
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			vt[st.top()] = true;
			st.pop();
		}
		for(int i = 0; i < s.length(); i++) {
			if(vt[i]) cout << -1;
			else cout << s[i];
		}
		cout << endl;
	}
	return 0;
}

