#include <iostream>

using namespace std;

long long F[51];

int solve(int n, long long k) {
	if(n == 1) return 1;
	long long m = F[n] / 2 + 1;
	if(k == m) return n;
	if(k < m) return solve(n - 1, k);
	return solve(n - 1, k - m);
}

int main() {
	F[1] = 1;
	for(int i = 2; i < 51; i++) {
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
