#include <iostream>

using namespace std;

int M = 1e9 + 7;

long long powMod(int n, int k) {
	if(k == 0) {
		return 1;
	}
	long long x = powMod(n, k / 2);
	if(k % 2 == 0) {
		return x * x % M;
	}
	return n * (x * x % M) % M;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << powMod(n, k) << endl;
	}
	return 0;
}


