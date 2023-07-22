#include <iostream>

using namespace std;

int n, k;
int a[20];
int b[20];
int prefixSum[20];
int kq;

bool check() {
	int sum = prefixSum[b[1]];
	for(int i = 2; i <= k; i++) {
		if(sum != prefixSum[b[i]] - prefixSum[b[i - 1]]) return false;
	}
	return true;
}

void quayLui(int i) {
	for(int j = b[i - 1] + 1; j <= n - k + i; j++) {
		b[i] = j;
		if(i == k - 1) {
			if(check()) {
				kq += 1;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	cin >> n >> k;
	cin >> a[1];
	prefixSum[1] = a[1];
	for(int i = 2; i <= n; i++) {
		cin >> a[i];
		prefixSum[i] = prefixSum[i - 1] + a[i];
	}
	if(prefixSum[n] % k || k < 1) {
		cout << 0;
	}
	else if(k == 1) cout << 1;
	else {
		b[0] = 0;
		b[k] = n;
		kq = 0;
		quayLui(1);
		cout << kq;
	}
	return 0;
}

