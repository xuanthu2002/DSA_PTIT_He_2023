#include <iostream>
#include <cstring>

using namespace std;

int F[1001][1001];

int qhd(string s) {
	int kq = 1, n = s.length();
	memset(F, 0, sizeof(F));
	for(int i = 0; i < n; i++) F[i][i] = 1;
	for(int k = 1; k < n; k++) {
		for(int i = 0; i < n - k; i++) {
			int j = i + k;
			if(s[i] == s[j] && k > 1) {
				F[i][j] = F[i + 1][j - 1];
			}
			else if(s[i] == s[j] && k == 1) F[i][j] = 1;
			else F[i][j] = 0;
			if(F[i][j] == 1) kq = max(kq, j - i + 1);
		}
	}
	return kq;
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

/*
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int kq = -1e9;
		int n = s.length();
		for(int i = 0; i < n; i++) {
			int l = i, r = i;
			while(s[l] == s[r] && l >= 0 && r < n) {
				kq = max(kq, r - l + 1);
				l--;
				r++;
			}
		}
		for(int i = 0; i < n - 1; i++) {
			int l = i, r = i + 1;
			while(s[l] == s[r] && l >= 0 && r < n) {
				kq = max(kq, r - l + 1);
				l--;
				r++;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

*/

