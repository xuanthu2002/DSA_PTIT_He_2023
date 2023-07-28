#include <iostream>
#include <stack>

using namespace std;

int solve(string s) {
	stack<int> st;
	int n = s.length();
	int kq = -1e9;
	st.push(-1);
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			st.push(i);
		}
		else {
			st.pop();
		}
		if(!st.empty()) {
			kq = max(kq, i - st.top());
		}
		else {
			st.push(i);
		}
	}
	return kq;
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

