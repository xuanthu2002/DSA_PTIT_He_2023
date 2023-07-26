#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int b[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		int l = 0, r = n - 1;
		string kq = "Yes";
		while(l < r) {
			if((a[l] != b[l] || a[r] != b[r]) && (a[r] != b[l] || a[l] != b[r])) {
				kq = "No";
				break;
			}
			l++;
			r--;
		}
		cout << kq << endl;
	}
	return 0;
}


