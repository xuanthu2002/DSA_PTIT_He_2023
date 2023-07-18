#include <iostream>

using namespace std;

string binaryToGray(string s) {
	string binary = "";
	binary += (char) s[0];
	for(int i = 1; i < s.length(); i++) {
		if(s[i - 1] == s[i]) {
			binary += "0";
		}
		else binary += "1";
	}
	return binary;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << binaryToGray(s) << endl;
	}
	return 0;
}

