#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, t = 0, d = 0;
	for(char c : s) {
		if(c == 'X') x += 1;
		else if(c == 'T') t += 1;
		else d += 1;
	}
	int cnt = 0, x1 = 0, d1 = 0;
	for(int i = 0; i < x; i++) {
		if(s[i] != 'X') cnt += 1;
		if(s[i] == 'D') d1 += 1;
	}
	for(int i = n - d; i < n; i++) {
		if(s[i] != 'D') cnt += 1;
		if(s[i] == 'X') x1 += 1;
	}
	cout << cnt - min(x1, d1);
	return 0;
}

