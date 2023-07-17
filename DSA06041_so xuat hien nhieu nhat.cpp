#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int, int> m;
		int x;
		for(int i = 0; i < n; i++) {
			cin >> x;
			m[x] += 1;
		}
		int max_freq = 0;
		int kq = -1;
		for(auto i : m) {
			if(i.second > max_freq) {
				max_freq = i.second;
				kq = i.first;
			}
		}
		if(max_freq > n / 2) {
			cout << kq << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

