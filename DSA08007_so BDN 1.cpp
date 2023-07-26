#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.length();
		int i = 0;
		while(i < n && s[i] < '2') {
			i++;
		}
		if(i < n) {
			for(int idx = i; idx < n; idx++) {
				s[idx] = '1';
			}
		}
		long long kq = 0;
		for(int idx = 0; idx < n; idx++) {
			kq = kq * 2 + s[idx] - '0';
		}
		cout << kq << endl;
	}
	return 0;
}


