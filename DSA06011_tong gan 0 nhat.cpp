#include <iostream>
#include <algorithm>
#include <cmath>

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
		int res = 1e9;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(abs(a[i] + a[j]) < abs(res)) {
					res = a[i] + a[j];
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}


