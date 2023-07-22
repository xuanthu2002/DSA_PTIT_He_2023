#include <iostream>

using namespace std;

int n, k;
int a[100];
int b[100];
int kq;
bool flag;

bool check() {
	for(int i = 1; i <= k; i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

void quayLui(int i) {
	for(int j = a[i -1] + 1; j <= n - k + i; j++) {
		if(flag) return;
		a[i] = j;
		if(i == k) {
			kq += 1;
			if(check()) {
				flag = true;
				return;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	a[0] = 0;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= k; i++) cin >> b[i];
		kq = 0;
		flag = false;
		quayLui(1);
		cout << kq << endl;
	}
	return 0;
}

