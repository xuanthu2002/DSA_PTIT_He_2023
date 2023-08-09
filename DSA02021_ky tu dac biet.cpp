#include <iostream>
#include <cmath>

using namespace std;

string s;
long long F[65];

char solve(int pos, long long n) {
	if(n <= s.length())
		return s[n - 1];
	if(n < F[pos - 1])
		return solve(pos - 1, n);
	else {
		n -= F[pos - 1];
		if(n == 1) return solve(pos - 1, F[pos - 1]);
		else return solve(pos - 1, n - 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		long long n;
		cin >> n;
		F[0] = s.length();
		int pos = 0;
		while(F[pos] < n) {
			pos += 1;
			F[pos] = F[pos - 1] * 2;
		}
		cout << solve(pos, n) << endl;
	}
	return 0;
}

