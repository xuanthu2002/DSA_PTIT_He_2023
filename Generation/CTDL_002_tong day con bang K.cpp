#include <iostream>

using namespace std;

bool ok;

void sinh(int a[], int n) {
	int i = n - 1;
	while(i >= 0 && a[i] == 1) {
		a[i] = 0;
		i -= 1;
	}
	if(i < 0) ok = false;
	else {
		a[i] = 1;
	}
}

bool check(int a[], int b[], int n, int k) {
	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i] * b[i];
	return sum == k;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int b[n] = {0};
	ok = true;
	int cnt = 0;
	while(ok) {
		if(check(a, b, n, k)) {
			for(int i = 0; i < n; i++) {
				if(b[i] > 0) cout << a[i] << " ";
			}
			cout << endl;
			cnt += 1;
		}
		sinh(b, n);
	}
	cout << cnt;
	return 0;
}

