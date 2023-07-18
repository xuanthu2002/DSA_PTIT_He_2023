#include <iostream>

using namespace std;

int sinh(int a[], int n, int k) {
	int i = k - 1, kq = 1;
	int cnt[n + 1] = {0};
	while(i >= 0 && a[i] == n - k + i + 1) {
		cnt[a[i]] += 1;
		i -= 1;
	}
	if(i < 0) return k;
	else {
		a[i] += 1;
		i += 1;
		while(i < k) {
			a[i] = a[i - 1] + 1;
			if(cnt[a[i]] == 0) {
				kq += 1;
			}
			i += 1;
		}
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < k; i++) cin >> a[i];
		cout << sinh(a, n, k) << endl;
	}
	return 0;
}

