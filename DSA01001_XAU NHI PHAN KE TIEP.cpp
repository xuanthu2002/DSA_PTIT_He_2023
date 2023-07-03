#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int i = s.length() - 1;
		while(s[i] == '1' && i >= 0) {
			s[i] = '0';
			i -= 1;
		}
		s[i] = '1';
		cout << s << endl;
	}
	return 0;
}

