#include <iostream>

using namespace std;

bool sequentialSearch(int a[], int l, int r, int x) {
	for(int i = l; i < r; i++) {
		if(a[i] == x) {
			return true;
		}
	}
	return false;
}



int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int kq = -1;
		for(int i = 0; i < n; i++) {
			if(sequentialSearch(a, i + 1, n, a[i])) {
				kq = a[i];
				break;
			}
		}
		if(kq == -1) cout << "NO" << endl;
		else cout << kq << endl;
	}
	return 0;
}

