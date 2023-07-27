#include <iostream>

using namespace std;

long long F[93];

char solve(int n, long long k) {
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k <= F[n - 2]) return solve(n - 2, k);
	return solve(n - 1, k - F[n - 2]);
}

int main() {
	F[0] = 0;
	F[1] = 1;
	for(int i = 2; i < 93; i++) F[i] = F[i -1] + F[i - 2];
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

