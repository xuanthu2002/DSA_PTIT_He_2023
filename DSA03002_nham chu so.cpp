#include <iostream>

using namespace std;

string replace(string s, char a, char b) {
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == a) {
			s[i] = b;
		}
	}
	return s;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << stoi(replace(a, '6', '5')) + stoi(replace(b, '6', '5')) << " ";
	cout << stoi(replace(a, '5', '6')) + stoi(replace(b, '5', '6'));
	return 0;
}

