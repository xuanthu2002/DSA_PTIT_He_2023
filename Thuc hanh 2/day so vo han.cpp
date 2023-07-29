#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

struct MaTran {
	int a[2][2];
	
	MaTran() {
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
	}
	
	friend MaTran operator * (MaTran A, MaTran B) {
		MaTran res;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				res.a[i][j] = 0;
				for(int k = 0; k < 2; k++) {
					res.a[i][j] += (long long) A.a[i][k] * B.a[k][j] % mod;
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

MaTran power(MaTran a, int k) {
	if(k == 1) return a;
	MaTran x = power(a, k / 2);
	if(k & 1) return a * x * x;
	return x * x;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		MaTran a;
		MaTran F = power(a, n);
		cout << F.a[1][0] << endl;
	}
	return 0;
}

