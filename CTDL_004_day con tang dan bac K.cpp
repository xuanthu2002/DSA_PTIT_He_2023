#include <iostream>

using namespace std;

int a[100];
int b[100];
int n, k;
int kq;

bool check() {
	int tmp = -1e9;
	for(int i = 0; i < n; i++) {
		if(b[i] == 1) {
			if(a[i] < tmp) {
				return false;
			}
			tmp = a[i];
		}
	}
	return true;
}

void quayLui(int i, int cnt) {
	if(cnt > k) return;
	for(int j = 0; j < 2; j++) {
		b[i] = j;
		cnt += j;
		if(i == n - 1) {
			if(cnt == k && check()) {
				kq += 1;
			}
		}
		else quayLui(i + 1, cnt);
		cnt -= j;
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	kq = 0;
	quayLui(0, 0);
	cout << kq;
	return 0;
}

