#include <iostream>
#include <cstring>

using namespace std;

long long f[100];

long long find(int idx, long long n, long long i) {
	if(idx == 1) return n % 2;
	long long tmp = f[idx - 1];
	if(i == tmp + 1) return n % 2;
	if(i < tmp + 1) return find(idx - 1, n / 2, i);
	return find(idx - 1, n / 2, i - tmp - 1);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n, l, r;
		cin >> n >> l >> r;
		memset(f, 0, sizeof(f));
		f[1] = 1;
		long long m = n;
		n /= 2;
		int idx = 2;
		while(n > 0) {
			f[idx] = f[idx - 1] * 2 + 1;
			n /= 2;
			idx += 1;
		}
		idx -= 1;
		long long kq = 0;
		for(long long i = l; i <= r; i++) {
			kq += find(idx, m, i);
		}
		cout << kq << endl;
	}
	return 0;
}

