#include <iostream>
#include <algorithm>

using namespace std;

bool check(int a[], int n, int pos) {
	for(int i = 0; i < n; i++) {
		if(a[i] / pos == a[i] / (pos + 1)) {
			return false;
		}
	}
	return true;
} 

int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int kq = 0;
	for(int i = b[0]; i >= 0; i--) {
		if(check(a, n, i)) {
			for(int j = 0; j < n; j++) {
				kq += a[j] / (i + 1) + 1;
			}
			break;
		}
	}
	cout << kq;
	return 0;
}

