#include <iostream>

using namespace std;

long long F[26];

char solve(int n, long long k) {
	if(n == 1) return 'A';
	long long m = F[n] / 2 + 1;
	if(k == m) return (char) n - 1 + 'A';
	if(k < m) return solve(n - 1, k);
	return solve(n - 1, k - m);
}

int main() {
	F[1] = 1;
	for(int i = 2; i < 26; i++) {
		F[i] = F[i - 1] * 2 + 1;
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		long long k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}
