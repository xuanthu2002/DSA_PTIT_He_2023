#include <iostream>

using namespace std;

int n;
long long s;
int a[31];
int kq;

void quayLui(int i, long long sum, int cnt) {
	if(sum == s) {
		kq = min(kq, cnt);
		return;
	}
	if(i < n) {
		if(sum + a[i] <= s) quayLui(i + 1, sum + a[i], cnt + 1);
		quayLui(i + 1, sum, cnt);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		for(int i = 0; i < n; i++) cin >> a[i];
		kq = 1e9;
		quayLui(0, 0, 0);
		if(kq == 1e9) cout << -1 << endl;
		else cout << kq << endl;
	}
	return 0;
}

