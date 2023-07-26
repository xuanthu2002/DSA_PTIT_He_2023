#include <iostream>

using namespace std;

void solve(int s, int d) {
	if(s > d * 9) {
		cout << -1 << endl;
		return;
	}
	int a[d] = {0};
	a[0] = 1;
	s -= 1;
	int i = d - 1;
	int cs = 9;
	while(i >= 1 && s >= 0) {
		if(s >= cs) {
			a[i] = cs;
			s -= cs;
			i -= 1;
		}
		else cs -= 1;
	}
	if(s > 0) a[0] += s;
	for(int i = 0; i < d; i++) cout << a[i];
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int s, d;
		cin >> s >> d;
		solve(s, d);
	}
	return 0;
}

