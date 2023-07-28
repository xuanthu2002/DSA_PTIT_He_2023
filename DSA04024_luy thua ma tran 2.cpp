#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

struct MaTran {
	int n, m;
	int **a;
	
	MaTran() {}
	
	MaTran(int height, int width) {
		m = width;
		n = height;
		a = new int * [n];
		for(int i = 0; i < n; i++) {
			a[i] = new int [m];
			for(int j = 0; j < m; j++) {
				a[i][j] = 0;
			}
		}
	}
	
	void nhap() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
	}
};

MaTran operator * (MaTran A, MaTran B) {
	MaTran res(A.n, B.m);
	for(int i = 0; i < A.n; i++) {
		for(int j = 0; j < B.m; j++) {
			for(int k = 0; k < A.m; k++) {
				res.a[i][j] += (long long) A.a[i][k] * B.a[k][j] % mod;
				res.a[i][j] %= mod;
			}
		}
	}
	return res;
}

MaTran power(MaTran a, int k) {
	if(k == 1) {
		return a;
	}
	MaTran x = power(a, k / 2);
	if(k & 1) return a * x * x;
	return x * x;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MaTran a(n, n);
		a.nhap();
		MaTran res = power(a, k);
		long long kq = 0;
		for(int i = 0; i < n; i++) {
			kq += res.a[i][n - 1];
			kq %= mod;
		}
		cout << kq << endl;
	}
	return 0;
}

