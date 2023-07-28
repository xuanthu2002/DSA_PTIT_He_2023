#include <iostream>

using namespace std;

int qhd(int a[], int n) {
	int b[n];
	int kq = 0;
	for(int i = 0; i < n; i++) {
		b[i] = 1;
		for(int j = 0; j < i; j++) {
			if(a[i] >= a[j]) {
				b[i] = max(b[i], b[j] + 1);
			}
		}
		kq = max(kq, b[i]);
	}
	return n - kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << qhd(a, n) << endl;
	}
	return 0;
}

