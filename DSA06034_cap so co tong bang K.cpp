#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k, x;
		cin >> n >> k;
		map<int, int> m;
		for(int i = 0; i < n; i++) {
			cin >> x;
			m[x] += 1;
		}
		long long kq = 0;
		for(auto i : m) {
			if(i.first * 2 == k) {
				kq += (long long) i.second * (i.second - 1);
			}
			else {
				kq += (long long) i.second * m[k - i.first];
			}
		}
		cout << kq / 2 << endl;
	}
	return 0;
}

