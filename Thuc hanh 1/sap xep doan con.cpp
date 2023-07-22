#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		int left[n], right[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		left[0] = a[0];
		right[n - 1] = a[n - 1];
		for(int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], a[i]);
		}
		for(int i = n - 2; i >= 0; i--) {
			right[i] = min(right[i + 1], a[i]);
		}
		vector<int> kq;
		for(int i = 0; i < n - 1; i++) {
			if(left[i] <= right[i + 1]) {
				kq.push_back(i + 1);
			}
		}
		cout << kq.size() << endl;
		for(int i : kq) cout << i << " ";
		cout << endl;
	}
	return 0;
}

