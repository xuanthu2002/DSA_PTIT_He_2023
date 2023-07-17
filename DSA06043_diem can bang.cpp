#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ps[n], x, sum = 0;
		cin >> x;
		ps[0] = x;
		sum += x;
		for(int i = 1; i < n; i++) {
			cin >> x;
			ps[i] = ps[i - 1] + x;
			sum += x;
		}
		int kq = -1;
		for(int i = 1; i < n; i++) {
			if(ps[i - 1] == sum - ps[i]) {
				kq = i + 1;
				break;
			}
		}
		cout << kq << endl;
	}
	return 0;
}
