#include <iostream>

using namespace std;

const int prime[] = {2, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
long long kq;
int n;

void quayLui(int i, long long res = 1, int cnt = 1) {
	if(cnt > n) return;
	if(cnt == n) kq = min(kq, res);
	int j = 1;
	while(res * prime[i] <= kq) {
		res *= prime[i];
		quayLui(i + 1, res, cnt * (j + 1));
		j += 1;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		kq = 1e18;
		quayLui(1);
		cout << kq << endl;
	}
	return 0;
}

