#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int kq = 0, xoa = 0;
		stack<char> st;
		for(char c : s) {
			if(st.empty()) st.push(c);
			else if(c == ']' && st.top() == '[') {
				xoa += 2;
				st.pop();
			}
			else if(c == '[' && st.top() == ']') {
				kq += st.size() + xoa;
				st.pop();
			}
			else if(c == '[') st.push(c);
			else if(st.top() == ']' && c == ']') st.push(c);
			if(st.empty()) xoa = 0;
		}
		cout << kq << endl;
	}
	return 0;
}
//2
//[]][][
//[][][]
