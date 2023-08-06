#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int kq = 0;
		stack<char> st;
		for(char c : s) {
			if(c == '(') {
				st.push(c);
			}
			else {
				if(!st.empty()) {
					kq += 2;
					st.pop();
				}
			}
		}
		cout << kq << endl;
	}
	return 0;
}

