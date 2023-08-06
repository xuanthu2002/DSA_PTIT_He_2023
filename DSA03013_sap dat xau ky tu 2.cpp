#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		string s;
		cin >> k >> s;
		int cnt[128] = {0};
		int _max = 0;
		for(char c : s) {
			cnt[c] += 1;
			_max = max(_max, cnt[c]);
		}
		if((_max - 1) * (k - 1) > s.length() - _max) cout << -1 << endl;
		else cout << 1 << endl;
	}
	return 0;
}

