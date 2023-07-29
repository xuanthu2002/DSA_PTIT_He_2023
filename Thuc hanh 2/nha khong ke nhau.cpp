#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 3];
		long long f[n + 3] = {0};
		for(int i = 3; i < n + 3; i++) {
			cin >> a[i];
			f[i] = max(f[i - 2], f[i - 3]) + a[i];
		}
		cout << max(f[n + 1], f[n + 2]) << endl;
	}
	return 0;
}

