#include <iostream>
#include <utility>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		pair<float, float> p[n];
		for(int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		int f[n];
		int kq = -1e9;
		for(int i = 0; i < n; i++) {
			f[i] = 1;
			for(int j = 0; j < i; j++) {
				if(p[j].first < p[i].first && p[i].second < p[j].second) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			kq = max(kq, f[i]);
		}
		cout << kq << endl;
	}
	return 0;
}

