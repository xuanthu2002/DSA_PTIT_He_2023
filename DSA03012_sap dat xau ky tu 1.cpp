#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		map<char, int> m;
		for(char c : s) {
			m[c] += 1;
		}
		int kq = 1;
		int n = s.length() / 2;
		if(s.length() % 2) {
			n += 1;
		}
		for(auto i : m) {
			if(i.second > n) {
				kq = -1;
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

