#include <iostream>
#include <stack>

using namespace std;

void show(stack<int> st) {
	if(!st.empty()) {
		int top = st.top();
		st.pop();
		show(st);
		cout << top << " ";
	}
}

int main() {
	stack<int> st;
	string s;
	while(cin >> s) {
		if(s.compare("push") == 0) {
			int n;
			cin >> n;
			st.push(n);
		}
		else if(s.compare("pop") == 0) {
			if(!st.empty()) st.pop();
		}
		else {
			if(!st.empty()) show(st);
			else cout << "empty";
			cout << endl;
		}
	}
	return 0;
}

