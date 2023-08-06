#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n + 1], f[n + 1] = {0};
	for(int i = 1; i <= n; i++) cin >> a[i];
	int s = 0;
	for(int i = 1; i <= n; i++) {
		f[a[i]] = f[a[i] - 1] + 1;
		s = max(s, f[a[i]]);
	}
	cout << n - s << endl;
	return 0;
}

