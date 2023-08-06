#include <iostream>
#include <algorithm>

using namespace std;

int count(int x, int b[], int m, int cnt[]) {
	if(x == 0) {
		return 0;
	}
	if(x == 1) {
		return cnt[0];
	}
	int *idx = upper_bound(b, b + m, x);
	int kq = (b + m) - idx;
	kq += (cnt[0] + cnt[1]);
	if(x == 2) {
		kq -= (cnt[3] + cnt[4]);
	}
	if(x == 3) {
		kq += cnt[2];
	}
	return kq;
}

int solve(int a[], int b[], int n, int m) {
	int cnt[5] = {0};
	for(int i = 0; i < m; i++) {
		if(b[i] < 5) {
			cnt[b[i]] += 1;
		}
	}
	sort(b, b + m);
	int kq = 0;
	for(int i = 0; i < n; i++) {
		kq += count(a[i], b, m, cnt);
	}
	return kq;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n>> m;
		int cnt = 0;
		int a[n], b[m];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		cout << solve(a, b, n, m) << endl;
	}
	return 0;
}

