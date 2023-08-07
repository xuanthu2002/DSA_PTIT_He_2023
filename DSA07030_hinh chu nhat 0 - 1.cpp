#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
				if(a[i][j] == 1 && i > 0) {
					a[i][j] = a[i - 1][j] + 1;
				}
			}
		}
		int kq = 0;
		for(int i = 0; i < n; i++) {
			stack<int> l, r;
			int left[m], right[m];
			for(int j = 0; j < m; j++) {
				while(!l.empty() && a[i][j] <= a[i][l.top()]) {
					l.pop();
				}
				if(l.empty()) left[j] = 0;
				else left[j] = l.top();
				l.push(j);
			}
			for(int j = m - 1; j >= 0; j--) {
				while(!r.empty() && a[i][j] <= a[i][r.top()]) {
					r.pop();
				}
				if(r.empty()) right[j] = m;
				else right[j] = r.top();
				r.push(j);
			}
			for(int j = 0; j < m; j++) {
				kq = max(kq, a[i][j] * (right[j] - left[j] - 1));
			}
		}
		cout << kq << endl;
	}
	return 0;
}

