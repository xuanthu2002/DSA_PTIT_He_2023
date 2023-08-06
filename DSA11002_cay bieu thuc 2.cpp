#include <iostream>
#include <queue>

using namespace std;

int solve(string s[], int n) {
	queue<int> st;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
			int b = st.front();
			st.pop();
			int a = st.front();
			st.pop();
			if(s[i] == "+") {
				st.push(a + b);
			}
			else if(s[i] == "-") {
				st.push(a - b);
			}
			else if(s[i] == "*") {
				st.push(a * b);
			}
			else if(s[i] == "/") {
				st.push(a / b);
			}
		}
		else st.push(stoi(s[i]));
	}
	return st.front();
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; i++) cin >> s[i];
		cout << solve(s, n) << endl;
	}
	return 0;
}

