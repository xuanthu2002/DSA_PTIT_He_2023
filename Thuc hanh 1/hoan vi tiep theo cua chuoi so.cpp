#include <iostream>

using namespace std;

string solve(string s) {
	int i = s.length() - 2;
	while(i >= 0 && s[i] >= s[i + 1]) {
		i -= 1;
	}
	if(i < 0) return "BIGGEST";
	int j = s.length() - 1;
	while(j > i && s[j] <= s[i]) {
		j -= 1;
	}
	swap(s[i], s[j]);
	i += 1;
	j = s.length() - 1;
	while(i < j) {
		swap(s[i], s[j]);
		i += 1;
		j -= 1;
	}
	return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << n << " " << solve(s) << endl;
	}
	return 0;
}

