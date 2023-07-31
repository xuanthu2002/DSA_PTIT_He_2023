#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int left[n], right[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		left[0] = 1;
		for(int i = 1; i < n; i++) {
			left[i] = 1;
			if(a[i] > a[i - 1]) {
				left[i] = left[i - 1] + 1;
			}
		}
		right[n - 1] = 1;
		for(int i = n - 2; i >= 0; i--) {
			right[i] = 1;
			if(a[i] > a[i + 1]) {
				right[i] = right[i + 1] + 1;
			}
		}
		int kq = 0;
		for(int i = 0; i < n; i++) {
			kq = max(kq, left[i] + right[i] - 1);
		}
		cout << kq << endl;
	}
	return 0;
}

