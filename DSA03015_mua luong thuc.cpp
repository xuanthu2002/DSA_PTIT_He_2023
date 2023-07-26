#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, s, m;
		cin >> n >> s >> m;
		if(n < m || 6 * n < 7 * m) {
			cout << "-1" << endl;
			continue;
		}
		double kq = (double) s * m / n;
		if(kq != (int) kq) {
			kq ++;
		}
		cout << (int) kq << endl;
	}
	return 0;
}

