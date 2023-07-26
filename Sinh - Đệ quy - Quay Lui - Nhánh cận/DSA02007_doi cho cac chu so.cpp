#include <iostream>

using namespace std;

string solve(string s, int i, int k) {
	if(k == 0 || i >= s.length()) {
		return s;
	}
	int idx = i;
	for(int j = i + 1; j < s.length(); j++) {
		if(s[j] >= s[idx]) {
			idx = j;
		}
	}
	if(s[idx] != s[i]) {
		swap(s[i], s[idx]);
		return solve(s, i + 1, k - 1);
	}
	return solve(s, i + 1, k);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		cout << solve(s, 0, k) << endl;
	}
	return 0;
}

