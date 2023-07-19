#include <iostream>

using namespace std;

int mod = 1e9 + 7;

long long binPow(long long x, long long n) {
	if(n == 0)
		return 1;
	long long tmp = binPow(x, n / 2) % mod;
	if(n & 1)
		return x * (tmp * tmp % mod) % mod;
	else
		return tmp * tmp % mod;
}

long long inv(long long n) {
	long long kq = 0;
	while(n) {
		kq = kq * 10 + n % 10;
		n /= 10;
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		long long r = inv(n);
		cout << binPow(n, r) << endl;
	}
	return 0;
}

