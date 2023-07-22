#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool cnt[10] = {false};
		while(n--) {
			string s;
			cin >> s;
			for(char c : s) {
				cnt[c - '0'] = true;
			}
		}
		for(int i = 0; i < 10; i++) {
			if(cnt[i]) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

