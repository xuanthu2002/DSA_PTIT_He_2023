#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, s, k;
		cin >> n >> s >> k;
		int a[n + 1];
		a[0] = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			a[i] = a[i - 1] + x;
		}
		int kq = -1;
		for(int i = 1; i <= s; i++) {
			if(a[s] - a[i - 1] <= k) {
				kq = i;
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

