#include <iostream>

using namespace std;

int qhd(string s) {
	int n = s.length(), F[50] = {0};
	if(s[0] == '0') {
		return 0;
	}
	F[0] = 1;
	F[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(s[i - 1] != '0') {
			F[i] = F[i - 1];
		}
		if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7') {
			F[i] = F[i] + F[i - 2];
		}
	}
	return F[n];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << qhd(s) << endl;
	}
	return 0;
}

