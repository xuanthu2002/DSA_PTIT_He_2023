#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int f[n];
		int kq = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			f[i] = a[i];
			for(int j = 0; j < i; j++) {
				if(a[i] > a[j]) {
					f[i] = max(f[i], f[j] + a[i]);
				}
			}
			kq = max(kq, f[i]);
		}
		cout << kq << endl;
	}
	return 0;
}

