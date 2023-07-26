#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int b[n];
	b[0] = 1;
	int kq = 0;
	for(int i = 1; i < n; i++) {
		b[i] = 0;
		for(int j = i - 1; j >= 0; j--) {
			if(a[i] > a[j]) {
				b[i] = max(b[i], b[j] + 1);
			}
			kq = max(kq, b[i]);
		}
	}
	cout << kq;
	return 0;
}

