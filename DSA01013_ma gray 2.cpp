#include <iostream>

using namespace std;

string grayToBinary(string s) {
	for(int i = 1; i < s.length(); i++) {
		s[i] = (char) (abs(s[i] - s[i - 1]) + '0');
	}
	return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << grayToBinary(s) << endl;
	}
	return 0;
}

