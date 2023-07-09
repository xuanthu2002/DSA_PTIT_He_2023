#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int l = 0, r = n - 1;
		string kq = "YES";
		while(l < r) {
			if(a[l] != a[r]) {
				kq = "NO";
				break;
			}
			l += 1;
			r -= 1;
		}
		cout << kq << endl;
	}
	return 0;
}

