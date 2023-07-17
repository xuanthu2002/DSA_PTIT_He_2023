#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt[100001] = {0};
		int a = 1e9, b = -1e9;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x] += 1;
			a = min(a, x);
			b = max(b, x);
		}
		int kq = 0;
		for(int i = a; i <= b; i++) {
			if(cnt[i] == 0) {
				kq += 1;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

