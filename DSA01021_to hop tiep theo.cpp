#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[k];
		for(int i = 0; i < k; i++) {
			cin >> a[i];
		}
		int i = k - 1;
		while(i >= 0 && a[i] == n - k + i + 1) {
			i -= 1;
		}
		int s = a[i] + 1;
		int res = 0;
		for(int j = 0; j < k - i; j++) {
			if(!binary_search(a + i, a + k, s + j)) {
				res += 1;
			}
		}
		if(i < 0) {
			res = k;
		}
		cout << res << endl;
	}
	return 0;
}

