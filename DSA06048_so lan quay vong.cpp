#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n + 1];
		a[0] = -1e9;
		int kq = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] < a[i - 1]) {
				kq = i - 1;
			}
		}
		cout << kq << endl;;
	}
	return 0;
}

