#include <iostream>

using namespace std;

int a[100];
int th[100];
int n, k;
bool kq;
int res;

bool check() {
	for(int i = 1; i <= k; i++) {
		if(a[i] != th[i]) return false;
	}
	return true;
}

void quayLui(int i) {
	if(kq) return;
	for(int j = th[i - 1] + 1; j <= n - k + i; j++) {
		th[i] = j;
		if(i == k) {
			res += 1;
			if(check()) {
				kq = true;
				return;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= k; i++) cin >> a[i];
		th[0] = 0;
		kq = false;
		res = 0;
		quayLui(1);
		cout << res << endl;
	}
	return 0;
}

