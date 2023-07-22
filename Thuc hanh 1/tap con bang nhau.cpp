#include <iostream>

using namespace std;

int n;
int a[101];
bool kq;
int s;


void quayLui(int i, int sum) {
	if(kq) return;
	if(sum == s) {
		kq = true;
		return;
	}
	if(i < n) {
		if(sum + a[i] <= s)quayLui(i + 1, sum + a[i]);
		quayLui(i + 1, sum);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum % 2) cout << "NO" << endl;
		else {
			kq = false;
			s = sum / 2;
			quayLui(0, 0);
			if(kq) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}

