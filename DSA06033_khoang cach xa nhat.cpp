#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int leftMin[n];
		leftMin[0] = a[0];
		for(int i = 1; i < n; i++) {
			leftMin[i] = min(leftMin[i - 1], a[i]);
		}
		int kq = -1;
		int i = n - 1, j = n - 1;
		while(i >= 0 && j >= 0) {
			if(a[j] > leftMin[i]) {
				kq = max(kq, j - i);
				i--;
			}
			else {
				j--;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

