#include <iostream>
#include <stack>

using namespace std;

int main() {
	int q;
	cin >> q;
	stack<int> st;
	string s;
	int x;
	while(q--) {
		cin >> s;
		if(s.compare("PUSH") == 0) {
			cin >> x;
			st.push(x);
		}
		else if(s.compare("POP") == 0) {
			if(!st.empty()) st.pop();
		}
		else {
			if(st.empty()) {
				cout << "NONE" << endl;
			}
			else cout << st.top() << endl;
		}
	}
	return 0;
}

