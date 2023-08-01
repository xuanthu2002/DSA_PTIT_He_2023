#include <iostream>
#include <stack>

using namespace std;

bool isDigits(char c) {
	return c >= '0' && c <= '9';
}

string solve(string s) {
	stack<int> hs;
	stack<string> ma;
	int n = s.length();
	if(s[0] == '[') hs.push(1);
	for(int i = 0; i < n; i++) {
		if(s[i] == '[' && !isDigits(s[i - 1]) && i > 0) {
			hs.push(1);
		}
		if(isDigits(s[i])) {
			int num = 0;
			while(isDigits(s[i])) {
				num = num * 10 + s[i] - '0';
				i += 1;
			}
			hs.push(num);
			i -= 1;
		}
		else if(s[i] == ']') {
			string tmp = "";
			while(!ma.empty() && ma.top() != "[") {
				tmp = ma.top() + tmp;
				ma.pop();
			}
			ma.pop();
			string x = "";
			int heSo = hs.top();
			hs.pop();
			while(heSo--) {
				x += tmp;
			}
			ma.push(x);
		}
		else ma.push(string(1, s[i]));
	}
	string kq = "";
	while(!ma.empty()) {
		kq = ma.top() + kq;
		ma.pop();
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

