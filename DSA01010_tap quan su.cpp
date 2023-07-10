#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a[100];
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < k; i++) cin >> a[i];
		int i = k - 1;
		while(a[i] == n - k + i + 1 && i >= 0) {
			i -= 1;
		}
		if(i < 0) {
			cout << k;
		}
		else {
			int kq = 0;
			for(int x = a[i] + 1; x < a[i] + k - i + 1; x++) {
				if(!binary_search(a + i, a + k, x)) {
					kq += 1;
				}
			}
			cout << kq;
		}
		cout << endl;
	}
	return 0;
}

