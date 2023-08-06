#include <iostream>
#include <stack>

using namespace std;

void solve(string s) {
	stack<int> st;
	int n = s.length();
	for(int i = 0; i <= n; i++) {
		st.push(i + 1);
		if(s[i] == 'I' || i == n) {
			while(!st.empty()) {
				cout << st.top();
				st.pop();
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		solve(s);
		cout << endl;
	}
	return 0;
}
