#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		int maxLeft[n + 1];
		maxLeft[0] = -1e9;
		int minRight[n + 2];
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			maxLeft[i] = max(maxLeft[i - 1], a[i]);
		}
		minRight[n + 1] = 1e9;
		for(int i = n; i >= 1; i--) {
			minRight[i] = min(minRight[i + 1], a[i]);
		}
		vector<int> kq;
		for(int i = 1; i <= n - 1; i++) {
			if(maxLeft[i] <= minRight[i + 1]) {
				kq.push_back(i);
			}
		}
		cout << kq.size() << endl;
		for(int i : kq) cout << i << " ";
		cout << endl;
	}
	return 0;
}

