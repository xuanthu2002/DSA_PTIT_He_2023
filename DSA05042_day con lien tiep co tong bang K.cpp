#include <iostream>
#include <unordered_map>

using namespace std;

string solve(int a[], int n, long long k) {
	unordered_map<long long, bool> m;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		if(sum == k || m[sum - k]) {
			return "YES";
		}
		m[sum] = true;
	}
	return "NO";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		long long k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << solve(a, n , k) << endl;
	}
	return 0;
}
