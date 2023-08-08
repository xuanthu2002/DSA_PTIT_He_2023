#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		int F[n + 1];
		F[0] = 0;
		F[1] = x;
		for(int i = 2; i <= n; i++) {
			F[i] = F[i - 1] + x;
			if(i % 2 == 0) {
				F[i] = min(F[i], F[i / 2] + z);
			}
			else {
				F[i] = min(F[i], min(F[i / 2] + z + x, F[i / 2 + 1] + z + y));
			}
		}
		cout << F[n] << endl;
	}
	return 0;
}

