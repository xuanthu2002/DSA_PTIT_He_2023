#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void print(stringstream &ss) {
	string s;
	if(ss >> s) {
		print(ss);
		cout << s << " ";
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		stack<string> st;
		stringstream ss(s);
		print(ss);
//		while(ss >> s) {
//			st.push(s);
//		}
//		while(!st.empty()) {
//			cout << st.top() << " ";
//			st.pop();
//		}
		cout << endl;
	}
	return 0;
}

