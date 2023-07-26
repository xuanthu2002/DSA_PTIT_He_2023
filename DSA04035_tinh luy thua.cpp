#include <iostream>

using namespace std;

int mod = 1e9 + 7;

long long binPow(int a, long long b) {
	if(b == 0) return 1;
	long long x = binPow(a, b / 2) % mod;
	if(b % 2 == 0) {
		return x * x % mod;
	}
	return a * x % mod * x % mod;
}

int main() {
	while(1) {
		int a;
		long long b;
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		cout << binPow(a, b) << endl;
	}
	return 0;
}

