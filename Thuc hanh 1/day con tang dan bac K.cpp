#include <iostream>

using namespace std;

int n, k;
int a[101];
int b[101];
int kq;

void quayLui(int i) {
	if(i == k + 1) {
		kq += 1;
		return;
	}
	if(i <= k) {
		for(int j = b[i - 1] + 1; j <= n - k + i; j++) {
			if(a[b[i - 1]] < a[j]) {
				b[i] = j;
				quayLui(i + 1);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -1e9;
	kq = 0;
	quayLui(1);
	cout << kq;
	return 0;
}

