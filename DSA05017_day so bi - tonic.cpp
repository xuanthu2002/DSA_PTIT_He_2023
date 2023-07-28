#include <iostream>

using namespace std;

int qhd(int a[], int n) {
	int sumLeft[n] = {0}, sumRight[n] = {0};
	for(int i = 0; i < n; i++) {
		sumLeft[i] = a[i];
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j]) {
				sumLeft[i] = max(sumLeft[i], sumLeft[j] + a[i]);
			}
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		sumRight[i] = a[i];
		for(int j = n - 1; j > i; j--) {
			if(a[i] > a[j]) {
				sumRight[i] = max(sumRight[i], sumRight[j] + a[i]);
			}
		}
	}
	int kq = -1e9;
	for(int i = 0; i < n; i++) kq = max(kq, sumLeft[i] + sumRight[i] - a[i]);
	return kq;
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

