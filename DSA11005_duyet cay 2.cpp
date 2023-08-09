#include <iostream>

using namespace std;

int n;
int in[10001], level[10001], mark[10001];

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> in[i];
		mark[in[i]] = i;
	}
	for(int i=1; i<=n; i++) {
		cin >> level[i];
	}
}

void solve(int l, int r) {
	if (l > r) return;
	if (l == r) cout << in[l] << " ";
	else {
		int pos;
		for(int i = 1; i <= n; i++) {
			if(mark[level[i]] >= l && mark[level[i]] <= r) {
				pos = level[i];
				break;
			}
		}
		pos = mark[pos];
		solve(l, pos - 1);
		solve(pos + 1, r);
		cout << in[pos] << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		solve(1, n);
		cout << endl;
	}
	return 0;
}
