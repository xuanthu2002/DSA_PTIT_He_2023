#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		int kq = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
			for(int j = 0; j < i; j++) {
				if(a[i] > a[j]) {
					b[i] = max(b[i], b[j] + a[i]);
				}
			}
			kq = max(kq, b[i]);
		}
		cout << kq << endl;
	}
	return 0;
}

