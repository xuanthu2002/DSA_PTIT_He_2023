#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int i = s.length() - 1;
		while(i >= 0 && s[i] == '0') {
			s[i] = '1';
			i -= 1;
		}
		if(i >= 0) {
			s[i] = '0';
		}
		cout << s << endl;
	}
	return 0;
}

