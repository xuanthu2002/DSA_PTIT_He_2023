#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int kq = -1;
		long long x;
		for(int i = 0; i < n - 1; i++) {
			cin >> x;
			if(x != a[i] && kq == -1) {
				kq = i + 1;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

