#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int kq = -1e9, s = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
			kq = max(kq, s);
			if(s < 0) s = 0;
		}
		cout << kq << endl;
	}
	return 0;
}

