#include <iostream>

using namespace std;

void solve(int n, int s) {
	if(s > 9 * n || s == 0) {
		cout << "-1 -1" << endl;
		return;
	}
	int a[n];
	a[0] = 1;
	int tmp = s - 1;
	int i = n - 1;
	int cs = 9;
	while(i >= 1 && tmp >= 0) {
		if(tmp >= cs) {
			a[i] = cs;
			tmp -= cs;
			i -= 1;
		}
		else cs -= 1;
	}
	if(tmp > 0) a[0] += tmp;
	for(int i = 0; i < n; i++) cout << a[i];
	cout << " ";
	cs = 9;
	i = 0;
	while(i < n && s >= 0) {
		if(s >= cs) {
			a[i] = cs;
			s -= cs;
			i += 1;
		}
		else cs -= 1;
	}
	for(int i = 0; i < n; i++) cout << a[i];
	cout << endl;
}

int main() {
	int n, s;
	cin >> n >> s;
	solve(n, s);
	return 0;
}
