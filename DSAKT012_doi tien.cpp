#include <iostream>

using namespace std;

int a[100];
int n, s;
int kq;

void quayLui(int i, int cnt, int sum) {
	if(sum > s || cnt >= kq) return;
	for(int j = 0; j < 2; j++) {
		sum += a[i] * j;
		cnt += j;
		if(i == n - 1) {
			if(sum == s) {
				kq = min(kq, cnt);
			}
		}
		else quayLui(i + 1, cnt, sum);
		sum -= a[i] * j;
		cnt -= j;
	}
}

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> a[i];
	kq = 1e9;
	quayLui(0, 0, 0);
	if(kq == 1e9) {
		cout << -1;
	}
	else cout << kq;
	return 0;
}

