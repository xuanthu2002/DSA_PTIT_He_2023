#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long a, b, n, m, x;
		cin >> a >> b;
		while(b % a) {
			n = a;
			m = b;
			x = b / a + 1;
			cout << "1/" << x << " + ";
			a = x * n - m;
			b = x * b;
		}
		cout << "1/" << b / a << endl;
	}
	return 0;
}

