#include <iostream>

using namespace std;

int n, s;
int T[31];
int kq;
int maxT, minT;

void quayLui(int i, int sum, int cnt) {
	if(sum + (n - i) * minT > s || sum + (n - i) * maxT < s) return;
	for(int j = 0; j < 2; j++) {
		cnt += j;
		sum += T[i] * j;
		if(i == n - 1) {
			if(sum == s) {
				kq = min(kq, cnt);
			}
		}
		else quayLui(i + 1, sum, cnt);
		sum -= T[i] * j;
		cnt -= j;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		maxT = -1e9;
		minT = 1e9;
		for(int i = 0; i < n; i++) {
			cin >> T[i];
			maxT = max(maxT, T[i]);
			minT = min(minT, T[i]);
		}
		kq = 1e9;
		quayLui(0, 0, 0);
		if(kq != 1e9) cout << kq << endl;
		else cout << -1 << endl;
	}
	return 0;
}

