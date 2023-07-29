#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int F[10001];

void add(string s) {
	stringstream ss(s);
	while(ss >> s) {
		if(s == "+") continue;
		int hs = 0, mu = 0;
		int i = 0;
		while(s[i] != '*') {
			hs = hs * 10 + s[i] - '0';
			i += 1;
		}
		i += 3;
		while(i < s.length()) {
			mu = mu * 10 + s[i] - '0';
			i += 1;
		}
		F[mu] += hs;
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string a, b;
		getline(cin, a);
		getline(cin, b);
		memset(F, 0, sizeof(F));
		add(a);
		add(b);
		string kq = "";
		for(int i = 10000; i >= 0; i--) {
			if(F[i] > 0) {
				kq += to_string(F[i]) + "*x^" + to_string(i) + " + ";
			}
		}
		kq.pop_back();
		kq.pop_back();
		kq.pop_back();
		cout << kq << endl;
	}
	return 0;
}
